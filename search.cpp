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

auto binary_search_ = [](vector<ll> &arr, ll k) -> ll
{
    ll l = 0, r = arr.size() - 1, cnt = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        cnt++;
        if (arr[mid] == k)
        {
            return cnt;
        }
        cnt++;
        if (arr[mid] < k)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return cnt;
};

auto ternary_search = [](vector<ll> &arr, ll k) -> ll
{
    ll l = 0, r = arr.size() - 1, cnt = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        cnt++;
        if (arr[mid] == k)
        {
            return cnt;
        }
        cnt++;
        if (arr[mid2] == k)
        {
            return cnt;
        }
        cnt++;
        if (k < arr[mid])
        {
            r = mid - 1;
            continue;
        }
        cnt++;
        if (k > arr[mid2])
        {
            l = mid2 + 1;
        }
        else
        {
            l = mid + 1;
            r = mid2 - 1;
        }
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
        ll search_2 = binary_search_(arr, i);
        ll search_3 = ternary_search(arr, i);
        cout << "for searching " << i << "\n\t Number of Comparison --> Binary : " << search_2 << " Ternary : " << search_3 << endl;
        graph.first.push_back(search_2);
        graph.second.push_back(search_3);
    }
    print_data();
    system("python plot.py");
    cout << "Graph plotted successfully!" << endl;
    return 0;
}