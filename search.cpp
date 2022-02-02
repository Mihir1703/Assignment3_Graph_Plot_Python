#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<vector<ll>, vector<ll>> graph;

auto print_data = []() -> void
{
    for (auto x : graph.first)
        cerr << x << " ";
    cerr << endl;
    for (auto x : graph.second)
        cerr << x << " ";
};

auto gen_array = [](vector<ll> &arr, ll n) -> void
{
    for (int i = 1; i <= n; i++)
    {
        cerr << i << " ";
        arr.push_back(i);
    }
    cerr << endl;
};

/**
* @params search = 2 -> binary_search
* @params search = 3 -> ternary_search
**/

auto _search = [](vector<ll> &arr, ll k, int search) -> ll
{
    ll l = 0, r = arr.size() - 1, cnt = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / search;
        cnt++;
        if (arr[mid] == k)
            return cnt;
        if (arr[mid] < k)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return cnt;
};

int main()
{
#ifndef file_output_for_graph_plotting
    freopen("output.txt", "w+", stderr);
#endif
    ll n;
    cin >> n;
    vector<ll> arr;
    gen_array(arr, n);
    for (int i = 1; i <= n; i++)
    {
        ll b = _search(arr, i, 2);
        ll t = _search(arr, i, 3);
        cout << "To search " << i << " Comparison : Binary = " << b << " Ternary = " << t << endl;
        graph.first.push_back(b);
        graph.second.push_back(t);
    }
    print_data();
    system("python plot.py");
    return 0;
}