/**
 * Matric: A0217988E
 * Name: Brendan Cheong Ern Jie
 * Lab: 10
 * TA: Fidella Widjojo
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long int;

void printPair(pair<ll, ll> pr) {
    cout << '<' << pr.first << ", " << pr.second << '>';
}

void printVec(vector<ll> arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (i > 0) cout << " ";
        cout << arr[i];
    }
    cout << "\n";
}

ll manhattanDistance(pair<ll, ll> pair1, pair<ll, ll> pair2) {
    ll distance;
    ll xDiff, yDiff;

    xDiff = llabs(pair1.first - pair2.first);
    yDiff = llabs(pair1.second - pair2.second);
    distance = xDiff + yDiff;
    return distance;
}

class Student {

    ll studentNumber;
    ll facultyIndex;
    pair<ll, ll> studentCell;

public:
    Student(pair<ll, ll> studentCell, ll studentNumber, ll facultyIndex) {
        this->studentNumber = studentNumber;
        this->facultyIndex = facultyIndex;
        this->studentCell = studentCell;
    }

    void toString() {
        cout << "Student "
            << studentNumber
            << " is from Faculty "
            << facultyIndex
            << " at cell ";
        printPair(studentCell);
    };

    ll getStudentNumber() {
        return studentNumber;
    };

    pair<ll, ll> getStudentCell() {
        return studentCell;
    }
};

bool compareStudent(Student& s1, Student& s2) {
    return s1.getStudentNumber() < s2.getStudentNumber();
}

class Faculty {
    vector<pair<ll, ll>> cells;
    vector<Student> students;
    vector<ll> distance;
    ll index;
    ll T;
public:
    Faculty(vector<pair<ll, ll>> cells, ll index) {
        this->cells = cells;
        this->index = index;
        this->T = 0;
    }

    void setT(ll T) {
        this->T = T;
    }

    void setStudents(Student stu) {
        students.push_back(stu);
    }

    void toString() {
        cout << "Faculty " << index << " cells: \n";
        for (pair<ll, ll> cell : cells) {
            cout << ' ';
            printPair(cell);
        }
        cout << '\n' << "with T value: " << T << '\n';

        cout << "I have students of: " << '\n';
        for (auto& stu : students) {
            stu.toString();
            cout << '\n';
        }
        cout << "My distances are: [";
        for (size_t i = 0; i < distance.size(); i++) {
            cout << distance[i] << ", ";
        }

        cout << ']' << '\n';
    }

    void sortCellsAndStudents() {
        sort(cells.begin(), cells.end());
        sort(students.begin(), students.end(), compareStudent);
    }

    vector<ll> getDistanceArray() {
        for (size_t idx = 0; idx < students.size(); ++idx) {
            pair<ll, ll> PAIR1 = cells[idx];
            pair<ll, ll> PAIR2 = students[idx].getStudentCell();

            ll calculatedDistance = manhattanDistance(PAIR1, PAIR2);
            distance.push_back(calculatedDistance);
        }
        sort(distance.begin(), distance.end());
        return distance;
    }
};

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll R, C, F, S, G;
    vector<Faculty> faculties;

    cin >> R >> C >> F >> S >> G;

    // Each faculty must know what students it needs
    // then from there, calculate the the distances for each student to its corresponding cell, sorted order so that each student knows which cell to go to.
    // sort the distances so that we just need to make the minimum steps with at least T students (we only need T students and we pick smallest first)
    // sort the final distances so that we meet the requirement by at least G faculties (we only need G faculties to be met)

    /**
     * Create a list of Faculties with its own index.
     * Each faculty knows what cells they have stored in an vector.
    */
    for (size_t v = 0; v < F; ++v) {
        vector<pair<ll, ll>> cells;
        ll num_of_cells = 0;
        cin >> num_of_cells;
        for (size_t i = 0; i < num_of_cells; i++) {
            ll row, col;
            cin >> row >> col;
            pair<ll, ll> cell(row, col);
            cells.push_back(cell);
        }
        Faculty f(cells, v + 1);
        faculties.push_back(f);
    }

    /**
     * Create a list of Students with its own index.
     * Each student knows which faculty it belongs to and the cell its in.
    */
    for (size_t i = 0; i < S; ++i) {
        ll r, c, studentNumber, facultyIndex = 0;
        cin >> r >> c >> studentNumber >> facultyIndex;
        Student student(pair<ll, ll>(r, c), studentNumber, facultyIndex);
        faculties[facultyIndex - 1].setStudents(student); // set Student for each faculty
    }

    /**
     * For each faculty
     * Get all the distances we need limited by T.
    */
    // vector<ll> totalDistance;
    vector<ll> finalDistance(F, 0);
    for (size_t i = 0; i < F; ++i) {
        ll T;
        cin >> T;
        faculties[i].sortCellsAndStudents();
        vector<ll> facultyDist = faculties[i].getDistanceArray();
        // for (size_t i = 0; i < T; ++i) {
        //     ll val = dist[i];
        //     // if (val)
        //     totalDistance.push_back(dist[i]);
        //     cout << "distance: " << dist[i] << ' ';
        // }
        // cout << '\n';

        for (size_t j = 0; j < T; ++j) {
            finalDistance[i] += facultyDist[j];
        }
    }

    // for (auto& fac : faculties) {
    //     fac.toString();
    // }

    // for (ll& d : finalDistance) {
    //     cout << "chosen distance: " << d << "\n";
    // }

    sort(finalDistance.begin(), finalDistance.end());
    ll answer = 0;
    for (size_t v = 0; v < G; ++v) {
        answer += finalDistance[v];
    }

    cout << answer << endl;


    return 0;
}