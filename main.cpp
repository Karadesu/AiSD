#include <iostream>

// void sdmin(int arr[], int n, int i) {
//     while (2*i + 1 < n) {
//         int l = 2*i + 1;
//         int r = 2*i + 2;
//         int sl = i;
//         int sr = i;
//         int ss = i;
//         if (arr[i] > arr[l]) {
//             sl = l;
//         }    
//         if (r < n and arr[i] > arr[r]) {
//             sr = r;
//         }
//         if (sl == i and sr == i) {
//             break;
//         }
//         if (sl != i and sr != i) {
//             ss = (arr[sr] < arr[sl]) ? sr : sl;
//         } else if (sl != i) {
//             ss = sl;
//         } else {
//             ss = sr;
//         }
//         std::swap(arr[ss], arr[i]);
//         i = ss;
//     }
// }

// void sdmax(int arr[], int n, int i) {
//     while (2*i + 1 < n) {
//         int l = 2*i + 1;
//         int r = 2*i + 2;
//         int sl = i;
//         int sr = i;
//         int ss = i;
//         if (arr[i] < arr[l]) {
//             sl = l;
//         }
//         if (r < n and arr[i] < arr[r]) {
//             sr = r;
//         }
//         if (sl == i and sr == i) {
//             break;
//         }
//         if (sl != i and sr != i) {
//             ss = (arr[sr] > arr[sl]) ? sr : sl;
//         } else if (sl != i) {
//             ss = sl;
//         } else {
//             ss = sr;
//         }
//         std::swap(arr[ss], arr[i]);
//         i = ss;
//     }
// }

int val[100000];
bool removed[100000];
int minh[100000];
int maxh[100000];
int res[100000];

void sdmin(int arr[], int n, int i) {
    while (2*i + 1 < n) {
        int ch = 2*i + 1;

        if (ch + 1 < n && val[arr[ch + 1]] < val[arr[ch]]) {
            ch += 1;
        }
        if (val[arr[ch]] >= val[arr[i]]) {
            break;
        }
        std::swap(arr[ch], arr[i]);
        i = ch;
    }
}

void sdmax(int arr[], int n, int i) {
    while (2*i + 1 < n) {
        int ch = 2*i + 1;

        if (ch + 1 < n && val[arr[ch + 1]] > val[arr[ch]]) {
            ch += 1;
        }
        if (val[arr[ch]] <= val[arr[i]]) {
            break;
        }
        std::swap(arr[ch], arr[i]);
        i = ch;
    }
}

void sumin(int arr[], int i) {
    while (i > 0) {
        int p = (i - 1) / 2;

        if (val[arr[p]] > val[arr[i]]) {
            std::swap(arr[p], arr[i]);
            i = p;
        } else {
            break;
        }
    }
}

void sumax(int arr[], int i) {
    while (i > 0) {
        int p = (i - 1) / 2;

        if (val[arr[p]] < val[arr[i]]) {
            std::swap(arr[p], arr[i]);
            i = p;
        } else {
            break;
        }
    }
}

int main() {
    int q;
    int n = 0;
    int imin = 0;
    int imax = 0;
    int r = 0;
    char s[50];

    std::cin >> q;

    for (int i = 0; i < q; ++i) {
        std::cin >> s;

        if (s[0] == 'I') {
            int x;
            std::sscanf(s, "Insert(%d)", &x);

            val[n] = x;

            minh[imin] = n;
            sumin(minh, imin);
            imin += 1;

            maxh[imax] = n;
            sumax(maxh, imax);
            imax += 1;

            n += 1;
        } else if (s[5] == 'n') {
            while (removed[minh[0]]) {
                imin -= 1;
                minh[0] = minh[imin];
                sdmin(minh, imin, 0);
            }
            res[r] = val[minh[0]];
            r += 1;
            removed[minh[0]] = true;
            imin -= 1;
            minh[0] = minh[imin];
            sdmin(minh, imin, 0);
        } else {
            while (removed[maxh[0]]) {
                imax -= 1;
                maxh[0] = maxh[imax];
                sdmax(maxh, imax, 0);
            }
            res[r] = val[maxh[0]];
            r += 1;
            removed[maxh[0]] = true;
            imax -= 1;
            maxh[0] = maxh[imax];
            sdmax(maxh, imax, 0);
        }
    }

    for (int i = 0; i < r; ++i) {
        std::cout << res[i] << '\n';
    }
    return 0;
}