
const int a = pow(1e9, 1./2);
vector<int> sieve;

void init() {
    bool n_prime[a+1];
    memset(n_prime, 0, sizeof(n_prime));

    for(int i = 2; i <= a; i++) {
        if (n_prime[i]) continue;
        sieve.push_back(i);
        for(int k = i * i; k <= a; k += i) n_prime[k] = true;
    }
}

unordered_map<int, unordered_map<int, int>> phi_cache;
int phi(int x, int a) {
    if (a == 0) return x;
    if (phi_cache.count(x) && phi_cache[x].count(a)) return phi_cache[x][a];
    return phi_cache[x][a] = phi(x, a-1) - phi(x / sieve[a-1], a-1);
}

unordered_map<int, int> pi_cache;
int pi(int x) {
    if (pi_cache.count(x)) return pi_cache[x];

    if (x <= sieve.back()) {
        int n;
        for(n = 0; n < sieve.size(); n++) {
            if (sieve[n] > x) break;
        }

        return pi_cache[x] = n;
    }

    int p_2 = 0;
    int l = pi(pow(x, 1./3));
    int h = pi(pow(x, 1./2));
    for(int i = l + 1; i <= h; i++) {
        p_2 += pi(x / sieve[i-1]) - (i-1);
    }

    int p_1 = phi(x, l) - p_2 - 1;
    return pi_cache[x] = p_1 + l;
}
