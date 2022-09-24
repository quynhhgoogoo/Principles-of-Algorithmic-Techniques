#include <iostream>
#include <queue>

bool better_positions(int applicant, int new_pos, int old_pos, int n, const int *a_pref)
{
    for(int i = 0; i < n; i ++) {
        if(a_pref[applicant*n+i] == new_pos) {
            return true;
        } else if(a_pref[applicant*n+i] == old_pos) {
            return false;
        }
    }
    return false;
}

void solver(int n, const int *a_pref, const int *b_pref, int *s)
{
    std::fill_n (s, n, -1);
    std::queue<int> indexes;
    for(int i = 0; i < n; i ++) {
        indexes.push(i);
    }
    
    bool *match = new bool[n];

    while(!indexes.empty()) {
        int p = indexes.front();
        indexes.pop();
        for(int applicant_index= 0; applicant_index < n; applicant_index++) {
            int app = b_pref[p*n+applicant_index];
            if(s[app] == -1) {
                s[app] = p;
                match[p] = true;
                break;
            } else {
                if(better_positions(app, p, s[app], n, a_pref)) {
                    indexes.push(s[app]);
                    match[s[app]] = false;
                    s[app] = p;
                    match[p] = true;
                    break;
                }
            }
        }
        if(!match[p]){
            indexes.push(p);
        }
    }
    delete[] match;
    return;
}

int main()
{
    int n = 3;
    const int a_pref [9] = {2,1,0,2,1,0,2,1,0};
    const int b_pref [9] = {1,2,0,1,2,0,1,2,0};
    int s [3];
    solver(n, a_pref, b_pref, s);
    std::cout<<s[0]<<s[1]<<s[2];
    return 0;


}
