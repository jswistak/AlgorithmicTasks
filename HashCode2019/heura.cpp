#include <random>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <chrono>

#define shandom_ruffle shuffle

using namespace std;

size_t set_buffer[256];

uint64_t nanos()
{
    uint64_t ns = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::
                  now().time_since_epoch()).count();
    return ns;
}

size_t butter(const vector<size_t>& A, const vector<size_t>& B)
{
    size_t r = 256;
    r = min(r, size_t(set_intersection(A.begin(), A.end(), B.begin(), B.end(), set_buffer) - set_buffer));
    r = min(r, size_t(set_difference(A.begin(), A.end(), B.begin(), B.end(), set_buffer) - set_buffer));
    r = min(r, size_t(set_difference(B.begin(), B.end(), A.begin(), A.end(), set_buffer) - set_buffer));
    return r;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	size_t n;
	cin >> n;
    vector<bool> ori(n);
    map<string, size_t> translate;
    vector<vector<size_t>> tags(n);
    vector<size_t> even, odd;
    for(size_t i = 0; i < n; i++)
    {
        char o;
        cin >> o;
        ori[i] = (o == 'V');
        size_t k;
        cin >> k;
        tags[i].reserve(k);
        for(size_t j = 0; j < k; j++)
        {
            string tag;
            cin >> tag;
            if(not translate.count(tag))
                translate[tag] = translate.size();
            tags[i].push_back(translate[tag]);
        }
        (ori[i] ? odd : even).push_back(i);
    }
    size_t seed = nanos() * (size_t)(new char);
    cerr << "seed = " << seed << endl;
    mt19937 gen(seed);
    auto randint = [&](size_t a, size_t b) {
        return uniform_int_distribution<size_t>{a, b}(gen);
    };
    shandom_ruffle(odd.begin(), odd.end(), gen);
    vector<pair<size_t, size_t>> slides; slides.reserve(n);
    vector<vector<size_t>> slide_tags; slide_tags.reserve(n);
    for(size_t j = 0; j+1 < odd.size(); j += 2)
    {
        slides.emplace_back(odd[j], odd[j+1]);
        slide_tags.emplace_back();
        auto& T = slide_tags.back();
        for(auto p : tags[odd[j]])
            T.push_back(p);
        for(auto p : tags[odd[j+1]])
            T.push_back(p);
        sort(T.begin(), T.end());
        T.erase(unique(T.begin(), T.end()), T.end());
    }
    for(auto i : even)
    {
        slides.emplace_back(i, -1u);
        slide_tags.emplace_back();
        for(auto p : tags[i])
            slide_tags.back().push_back(p);
        sort(slide_tags.back().begin(), slide_tags.back().end());
    }
    vector<size_t> run(slides.size());
    iota(run.begin(), run.end(), 0);
    
    const size_t p = slides.size();

    auto bread = [&](size_t x, const vector<size_t>& A) {
        size_t r = 0;
        if(x > 0)
            r += butter(A, slide_tags[run[x-1]]);
        if(x+1 < p)
            r += butter(A, slide_tags[run[x+1]]);
        return r;
    };
    auto sandwich = [&]() {
        size_t r = 0;
        for(size_t i = 0; i+1 < p; i++)
            r += butter(slide_tags[run[i]], slide_tags[run[i+1]]);
        return r;
    }; (void)sandwich;

    shandom_ruffle(run.begin(), run.end(), gen);
    size_t r1 = sandwich();
    cerr << "pre = " << r1 << endl;
    if(p > 1) for(size_t t = 0; t < (1 << 27); t++)
    {
        if(t % (1<<18) == 0) cerr << (t>>18) << " ";
        size_t x = 0, y = 0;
        do {
             x = randint(0, p-1), y = randint(0, p-1);
        } while(x == y);
        if(x > y) swap(x, y);
        if(bread(x, slide_tags[run[x]]) + bread(y, slide_tags[run[y]])
         < bread(x, slide_tags[run[y]]) + bread(y, slide_tags[run[x]]))
            swap(run[x], run[y]);
    } cerr << endl;
    cout << p << "\n";
    for(auto x : run)
    {
        if(slides[x].second == -1u)
            cout << slides[x].first;
        else
            cout << slides[x].first << " " << slides[x].second;
        cout << "\n";
    }
    size_t r2 = sandwich();
    cerr << "final = " << r2 << endl;
}
