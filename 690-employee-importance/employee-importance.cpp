/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int ans = 0;
    void s(Employee* root, vector<Employee*> employees) {
        ans += root->importance;
        auto v = root->subordinates;
        if (v.empty())
            return;

        for (auto x : v) {
            for (auto y : employees) {
                if (y->id == x)
                    s(y, employees);
            }
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        ans = 0;
        Employee* root = nullptr;
        for (int i = 0; i < employees.size(); i++) {
            if (employees[i]->id == id) {
                root = employees[i];
                break;
            }
        }
        s(root, employees);
        return ans;
    }
};