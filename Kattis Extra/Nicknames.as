import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;

public class Nicknames {
    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        public Reader()
        {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public Reader(String file_name) throws IOException
        {
            din = new DataInputStream(
                    new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String readLine() throws IOException
        {
            byte[] buf = new byte[64]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n') {
                    if (cnt != 0) {
                        break;
                    }
                    else {
                        continue;
                    }
                }
                buf[cnt++] = (byte)c;
            }
            return new String(buf, 0, cnt);
        }

        public int nextInt() throws IOException
        {
            int ret = 0;
            byte c = read();
            while (c <= ' ') {
                c = read();
            }
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (neg)
                return -ret;
            return ret;
        }

        public long nextLong() throws IOException
        {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }

        public double nextDouble() throws IOException
        {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();

            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }

            if (neg)
                return -ret;
            return ret;
        }

        private void fillBuffer() throws IOException
        {
            bytesRead = din.read(buffer, bufferPointer = 0,
                    BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte read() throws IOException
        {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }

        public void close() throws IOException
        {
            if (din == null)
                return;
            din.close();
        }
    }
    public static void main(String[] args) throws IOException {
        Reader br = new Reader();
        PrintWriter writer = new PrintWriter(System.out);
        StringBuilder result = new StringBuilder();
        int numNames = br.nextInt();
        AVL tree = new AVL();
        for (int i = 0; i < numNames; i++) {
            String name = br.readLine();
            tree.insert(new Node(name));
//            tree.inOrder();
        }
        int numNick = br.nextInt();
        for (int k = 0; k < numNick; k++) {
            String nick = br.readLine();
            Pair left = tree.left(nick);
            Pair right = tree.right(nick);
            if (left.node == null) {
                result.append(0);
                result.append("\n");
            } else {
                if (left.node == right.node) {
                    result.append(1);
                } else {
                    result.append(right.rank - left.rank + 1);
                }
                result.append("\n");
            }
        }
        writer.print(result);
        writer.flush();
    }
}

class Node {
    String str;
    int height, size;
    Node left, right, parent;
    Node(String str) {
        this.str = str;
        this.left = null;
        this.right = null;
        this.parent = null;
        this.height = 1;
        this.size = 1;
    }
    void rotateLeft() {
        Node temp = this.right;
        if (temp.left != null) {
            this.right = temp.left;
            temp.left.parent = this;
        } else {
            this.right = null;
        }
        if (this.parent != null) {
            if (this.parent.left == this) {
                this.parent.left = temp;
            } else {
                this.parent.right = temp;
            }
            temp.parent = this.parent;
        } else {
            temp.parent = null;
        }
        this.parent = temp;
        temp.left = this;
        this.height = Math.max((this.left == null ? 0 : this.left.height), (this.right == null ? 0 : this.right.height)) + 1;
        this.size = (this.left == null ? 0 : this.left.size) + (this.right == null ? 0: this.right.size) + 1;
        temp.height = Math.max(this.height, (temp.right == null ? 0 : temp.right.height)) + 1;
        temp.size = (this.size) + (temp.right == null ? 0 : temp.right.size) + 1;
    }
    void rotateRight() {
        Node temp = this.left;
        if (temp.right != null) {
            temp.right.parent = this;
            this.left = temp.right;
        } else {
            this.left = null;
        }
        if (this.parent != null) {
            if (this.parent.left == this) {
                this.parent.left = temp;
            } else {
                this.parent.right = temp;
            }
            temp.parent = this.parent;
        } else {
            temp.parent = null;
        }
        temp.right = this;
        this.parent = temp;
        this.height = Math.max((this.left == null ? 0 : this.left.height), (this.right == null ? 0 : this.right.height)) + 1;
        this.size = (this.left == null ? 0 : this.left.size) + (this.right == null ? 0: this.right.size) + 1;
        temp.height = Math.max((temp.left == null ? 0 : temp.left.height), this.height) + 1;
        temp.size = (temp.left == null ? 0 : temp.left.size) + (this.size) + 1;
    }
    @Override
    public String toString() {
        return String.format("%s %s %s", this.str, this.size, this.height);
    }
}

class AVL {
    Node root;
    AVL() {
        this.root = null;
    }
    //Find left
    Pair left(String s) {
        Node curr = root;
        Pair left = new Pair(null, -1);
        int rank = 0;
        while (curr != null) {
            if (curr.str.indexOf(s) == 0) {
                rank += (curr.left == null ? 0 : curr.left.size) + 1;
                left = new Pair(curr, rank);
                rank -= (curr.left == null ? 0 : curr.left.size) + 1;
                curr = curr.left;
            } else if (curr.str.compareTo(s) > 0) {
                curr = curr.left;
            } else {
                rank += (curr.left == null ? 0 : curr.left.size) + 1;
                curr = curr.right;
            }
        }
        return left;
    }
    //Find right
    Pair right(String s) {
        Node curr = root;
        Pair right = new Pair(null, -1);
        int rank = 0;
        while (curr != null) {
            if (curr.str.indexOf(s) == 0) {
                rank += (curr.left == null ? 0 : curr.left.size) + 1;
                right = new Pair(curr, rank);
                curr = curr.right;
            } else if (curr.str.compareTo(s) > 0) {
                curr = curr.left;
            } else {
                rank += (curr.left == null ? 0 : curr.left.size) + 1;
                curr = curr.right;
            }
        }
        return right;
    }
    //Insert
    void insert(Node n) {
        if (this.root == null) {
            this.root = n;
        } else {
            insert(root, n);
        }
    }

    void insert(Node node, Node toInsert) {
        if (node.str.compareTo(toInsert.str) > 0) { //node > toInsert
            if (node.left == null) {
                node.left = toInsert;
                toInsert.parent = node;
            } else {
                insert(node.left, toInsert);
            }
        } else { //node <= toInsert
            if (node.right == null) {
                node.right = toInsert;
                toInsert.parent = node;
            } else {
                insert(node.right, toInsert);
            }
        }
        rebalance(node);
    }

    void rebalance(Node n) {
        //Update current height
        n.height = Math.max((n.left == null ? 0 : n.left.height), (n.right == null ? 0 : n.right.height)) + 1;
        //Update current size
        n.size = (n.left == null ? 0 : n.left.size) + (n.right == null ? 0 : n.right.size) + 1;
        //Find balance factor
        int bf = (n.left == null ? 0 : n.left.height) - (n.right == null ? 0 : n.right.height);
        if (bf > 1) {
            int bf2 = (n.left.left == null ? 0 : n.left.left.height) - (n.left.right == null ? 0 : n.left.right.height);
            if (bf2 > 0) { //Left-left
                n.rotateRight();
            } else { //Left-right
                n.left.rotateLeft();
                n.rotateRight();
            }
            if (this.root == n && n.parent != null) {
                this.root = n.parent;
            }
        } else if (bf < -1) {
            int bf2 = (n.right.left == null ? 0 : n.right.left.height) - (n.right.right == null ? 0 : n.right.right.height);
            if (bf2 > 0) { //Right-left
                n.right.rotateRight();
                n.rotateLeft();
            } else { //Right-right
                n.rotateLeft();
            }
            if (this.root == n && n.parent != null) {
                this.root = n.parent;
            }
        }
    }

    void inOrder() {
        inOrder(this.root);
    }
    void inOrder(Node node) {
        if (node.left != null) {
            inOrder(node.left);
        }
        System.out.println(node);
        if (node.right != null) {
            inOrder(node.right);
        }
    }
}

class Pair {
    Node node;
    int rank;
    Pair(Node node, int rank) {
        this.node = node;
        this.rank = rank;
    }
}