#include <iostream>
#include <deque>
#include <string>
using namespace std;

class Queueueue {
private:
    deque<int> hq, vq;
    int h_size = 0, v_size = 0;
    int h_mid = -1, v_mid = -1;
    
public:
    void hpush(int x) {
        hq.push_back(x);
        h_size++;
        h_mid = (h_size + 1) / 2 - 1;
        
        if (v_size == 0) {
            vq.push_back(x);
            v_size++;
            v_mid = 0;
        } else {
            vq[v_mid] = hq[h_mid];
        }
    }
    
    void vpush(int x) {
        vq.push_back(x);
        v_size++;
        v_mid = (v_size + 1) / 2 - 1;
        
        if (h_size == 0) {
            hq.push_back(x);
            h_size++;
            h_mid = 0;
        } else {
            hq[h_mid] = vq[v_mid];
        }
    }
    
    int hpop() {
        if (h_size == 0) return -1;
        int front = hq.front();
        
        if (h_size == 1) {
            if(v_size == 1){
                hq.pop_back();
                vq.pop_back();
                h_size = v_size = 0;
                h_mid = v_mid = -1;
            }
            else{
                vq.erase(vq.begin() + v_mid);
                v_size--;
                v_mid = (v_size + 1) / 2 - 1;
                hq[0] = vq[v_mid];
            }
        } else {
            hq.pop_front();
            h_size--;
            h_mid = (h_size + 1) / 2 - 1;
            if (!vq.empty()) {
                vq[v_mid] = hq[h_mid];
            }
        }
        return front;
    }
    
    int vpop() {
    if (v_size == 0) return -1;
    int front = vq.front();
    
    if (v_size == 1) {
        if(h_size == 1){
            vq.pop_back();
            hq.pop_back();
            v_size = h_size = 0;
            v_mid = h_mid = -1;
        }
        else{
            hq.erase(hq.begin() + h_mid);
            h_size--;
            h_mid = (h_size + 1) / 2 - 1;
            vq[0] = hq[h_mid];
        }
    } else {
        vq.pop_front();
        v_size--;
        v_mid = (v_size + 1) / 2 - 1;
        if (!hq.empty()) {
            hq[h_mid] = vq[v_mid];
        }
    }
    return front;
}
    
    int hfront() { return h_size == 0 ? -1 : hq.front(); }
    int hback() { return h_size == 0 ? -1 : hq.back(); }
    int vfront() { return v_size == 0 ? -1 : vq.front(); }
    int vback() { return v_size == 0 ? -1 : vq.back(); }
    int hsize() { return h_size; }
    int vsize() { return v_size; }
    int size() { return h_size + v_size - (h_size == 0 ? 0 : 1); }
    bool empty() { return h_size == 0 && v_size == 0; }
    int middle() {
        if (empty()) return -1;
        return hq[h_mid];
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;
    
    Queueueue q;
    string cmd;
    int x;
    
    while (N--) {
        cin >> cmd;
        if (cmd == "hpush") {
            cin >> x;
            q.hpush(x);
        }
        else if (cmd == "vpush") {
            cin >> x;
            q.vpush(x);
        }
        else if (cmd == "hpop") cout << q.hpop() << '\n';
        else if (cmd == "vpop") cout << q.vpop() << '\n';
        else if (cmd == "hfront") cout << q.hfront() << '\n';
        else if (cmd == "hback") cout << q.hback() << '\n';
        else if (cmd == "vfront") cout << q.vfront() << '\n';
        else if (cmd == "vback") cout << q.vback() << '\n';
        else if (cmd == "hsize") cout << q.hsize() << '\n';
        else if (cmd == "vsize") cout << q.vsize() << '\n';
        else if (cmd == "size") cout << q.size() << '\n';
        else if (cmd == "empty") cout << q.empty() << '\n';
        else if (cmd == "middle") cout << q.middle() << '\n';
    }
    
    return 0;
}