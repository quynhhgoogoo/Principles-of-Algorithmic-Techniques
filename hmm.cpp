#include <iostream>
#include <queue>

bool better_applicants(const int *b_pref, int p, int new_a, int a, int N)
{
    for (int i = 0; i < N; i++)
    {
        // If a comes before new_a in list of a, then p prefers current applicant, don't do anything
        if (b_pref[a*N+i]  == new_a)
        {
            return true;
        }
  
        // If new_a comes before a in a's list, then free current applicant and match position with a
        else if (b_pref[a*N+i] == a)
        {
            return false;
        }
    }
    return false;
}

void solver(int n, const int *a_pref, const int *b_pref, int *s)
{
    std::fill_n (s, n, -1);
    std::queue<int> app_indexes;
    bool *matched = new bool[n];
    
    for(int i = 0; i < n; i ++) {
        app_indexes.push(i);
    } 

    while(!app_indexes.empty()) {
        int curr_app = app_indexes.front();
        app_indexes.pop();
        
        for(int i = 0; i < n; i++) {
            int pos = a_pref[curr_app*n+i];
            
            // If there exits a position does not have a match, match current applicant to position
            if(s[pos] == -1)
            {
                s[pos] = curr_app;
                matched[curr_app] = true;
                break;
            }
            else
            {
                // If current applicant is better, match the position to current applicant
                // Empty the previous match with old applicants
                if(better_applicants(b_pref, pos, curr_app, s[pos], n)) {
                    app_indexes.push(s[pos]);
                    matched[s[pos]] = false;
                    s[pos] = curr_app;
                    matched[curr_app] = true;
                    break;
                }
            }
            //s[pos] = curr_app;
            //matched[curr_app] = true;
        }
        if(!matched[curr_app]){
            app_indexes.push(curr_app);
        }
    }
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
