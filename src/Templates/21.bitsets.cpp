#include <iostream>
#include <unordered_set>
#include <vector>
#include <sstream>

using namespace std;

class BitSet {

    // n >> 5 == n / 32
    // n & 0x1F == n % 32 

    private:
    
        vector <unsigned int> st;
        int ran;
        int nums;

    public:

        BitSet(int size) {

            st.resize((size + 31) / 32);
            fill(st.begin(), st.end(), 0);
            
            ran = 32 * ((size + 31) / 32);
            nums = (size + 31) / 32;

        }
        
        int getran() {

            return ran;

        }

        void add(int n) {

            st[n / 32] |= 1U << (n % 32); 

        }

        void del(int n) {

            st[n / 32] &= ~(1U << (n % 32));

        }

        void rev(int n) {

            st[n / 32] ^= (1U << (n % 32));

        }

        bool contain(int n) {

            return ((st[n / 32] >> (n % 32)) & 1U);

        }
        

};

void test() {

    srand(time(NULL));

    cout << "Test Begin" << endl;

    int n = 1000;
    BitSet bitset(n);
    n = bitset.getran();

    unordered_set <int> st;

    int ops = 10000;

    for (int i = 0; i < ops; i++) {

        double p = rand() * 1.0 / RAND_MAX;
        int num = static_cast <int> (rand() / (RAND_MAX + 1.0) * n);

        if (p < 0.333) {

            bitset.add(num);
            st.insert(num);

        } else if (p < 0.666) {

            bitset.del(num);
            st.erase(num);

        } else {

            bitset.rev(num);

            if (st.find(num) != st.end()) st.erase(num);
            else st.insert(num);

        }

    }

    for (int i = 0; i < n; i++) {

        if (st.find(i) != st.end()) {

            cout << (bitset.contain(i) ? "" : "WA\n");

        } else {

            cout << (bitset.contain(i) ? "WA\n" : "");

        }

    }

    cout << "Test End" << endl;

}

int main() {

    test();

}

class CBitset {
    
    private:

        vector <unsigned int> st;
        
        int zeros;
        int ones;
        int reverse;
        int size;
        int nums;


    public:
        CBitset(int size) {
            
            this->size = size;
            nums = (size + 31) / 32;

            st.resize(nums);
            fill(st.begin(), st.end(), 0);

            ones = 0;
            zeros = size;
            reverse = false;

        }
        
        void fix(int idx) {
            
            int num = idx / 32;
            idx %= 32;
            
            if (!reverse) {

                if (!((st[num] >> idx) & 1)) {

                    st[num] |= (1U << idx);

                    zeros--;
                    ones++;

                }

            } else {

                if ((st[num] >> idx) & 1) {

                    st[num] ^= (1U << idx);

                    zeros--;
                    ones++;

                }

            }

        }
        
        void unfix(int idx) {
            
            int num = idx / 32;
            idx %= 32;
            
            if (!reverse) {

                if (((st[num] >> idx) & 1)) {

                    st[num] &= ~(1U << idx);

                    zeros++;
                    ones--;

                }

            } else {

                if (!((st[num] >> idx) & 1)) {

                    st[num] |= (1U << idx);

                    zeros++;
                    ones--;

                }

            }

        }
        
        void flip() {
            
            reverse = !reverse;
            
            swap(zeros, ones);

        }
        
        bool all() {
            
            return ones == size;

        }
        
        bool one() {
            
            return ones > 0;

        }
        
        int count() {
            
            return ones;

        }
        
        string toString() {
            
            ostringstream ss;

            for (int i = 0, k = 0; k < nums && i < size; k++) 
                
                for (int j = 0; j < 32 && i < size; j++, i++) {

                    int stats = ((st[k] >> j) & 1);
                    stats = reverse ? (!stats) : stats; 

                    ss << (stats ? '1' : '0');

                }

            return ss.str();

        }
    };
    