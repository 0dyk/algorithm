#include <iostream>

using namespace std;

int arr[200001];
int score[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    N *= 24;

    int sum = 0;

    for (int i = 0; i < M; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }

    int tmp = 0;
    for (int i = 0; i < M; ++i) {
        cin >> tmp;

        int k = 100 - arr[i];

        score[tmp] += k / tmp;
        score[k - (k / tmp) * tmp] += 1;
    }

    for (int i = 100; i > 0; --i) {
        if (score[i] >= N) {
            sum += i * N;
            break;
        }
        else if(score[i] < N) {
            sum += i * score[i];
            N -= score[i];
        }
    }

    cout << sum << '\n';

    return 0;
}