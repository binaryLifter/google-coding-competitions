#include <bits/stdc++.h>

const int LIMIT = 16;

int get_from_str(const std::string& s) {
  int ans = 0;
  for (int i = 0; i < s.size(); i += 1) {
    if (s[i] == '0') {
      continue;
    }
    ans += (1 << (s.size() - i - 1));
  }
  return ans;
}

int get_flipped(const int N) {
  if (N == 0) {
    return 1;
  }
  int ans = 0;
  for (int i = 0; (1LL << i) <= N; i += 1) {
    if (not(N & (1LL << i))) {
      ans |= (1LL << i);
    }
  }
  return ans;
}

std::string solve(const int S, const int E) {
  std::queue<int> q;
  std::map<int, int> dist;
  dist[S] = 0;
  q.push(S);
  while (not q.empty()) {
    const int i = q.front();
    q.pop();
    if (i == E) {
      return std::to_string(dist[i]);
    }
    const int nxt_dist = dist[i] + 1;
    const int nxt_a = i << 1;
    if (nxt_a >= 0 and nxt_a < (1 << LIMIT) and
        (not dist.count(nxt_a) or nxt_dist < dist[nxt_a])) {
      q.push(nxt_a);
      dist[nxt_a] = nxt_dist;
    }
    const int nxt_b = get_flipped(i);
    if (nxt_b >= 0 and nxt_b < (1 << LIMIT) and
        (not dist.count(nxt_b) or nxt_dist < dist[nxt_b])) {
      q.push(nxt_b);
      dist[nxt_b] = nxt_dist;
    }
  }
  return "IMPOSSIBLE";
}

void solve_test_case(const int test) {
  std::string s, e;
  std::cin >> s >> e;
  assert(s.size() + e.size() <= LIMIT);
  std::cout << "Case #" << test << ": "
            << solve(get_from_str(s), get_from_str(e)) << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  int T;
  std::cin >> T;
  for (int test = 1; test <= T; test += 1) {
    solve_test_case(test);
  }
  return 0;
}