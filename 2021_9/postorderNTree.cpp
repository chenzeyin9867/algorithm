class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> value;
        stack<pair<Node*, int>> s;
        auto cur = pair(root, 0);
        while (!s.empty() || cur.first != nullptr) {
            while (cur.first != nullptr) {
                s.push(cur);
                if (cur.first->children.size() > 0)
                    cur = pair(cur.first->children[0], 0);
                else
                    cur.first = nullptr;
            }
            cur = s.top();
            s.pop();
            if (cur.first->children.size() == 0 || cur.second >= cur.first->children.size()) {
                value.emplace_back(cur.first->val);
                cur.first = nullptr;
            }
            else {
                ++cur.second;
                s.push(cur);
                if (cur.second < cur.first->children.size())
                    cur = pair(cur.first->children[cur.second], 0);
                else
                    cur.first = nullptr;
            }
        }
        return value;
    }
};
