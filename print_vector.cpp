void print_vector(vector<int> &a) {
    for (auto x: a) {
        cout << x << " ";
    }
    cout << endl;
}

void print_2d(vector<vector<int>> &arr) {
    int n = arr.size();
    int m = arr[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}