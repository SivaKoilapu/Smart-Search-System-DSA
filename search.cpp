#include <bits/stdc++.h>
using namespace std;

vector<string> words;
unordered_map<string, int> freq;

// Add word
void addWord(string word) {
    words.push_back(word);
    freq[word] = 0;
}

// Binary search for prefix
int lowerBoundPrefix(string prefix) {
    int l = 0, r = words.size() - 1, ans = words.size();

    while (l <= r) {
        int mid = (l + r) / 2;
        if (words[mid].substr(0, prefix.size()) >= prefix) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

// Search function
void searchPrefix(string prefix) {
    if (prefix.empty()) {
        cout << "Please enter a valid prefix\n";
        return;
    }

    int start = lowerBoundPrefix(prefix);
    vector<string> results;

    for (int i = start; i < words.size(); i++) {
        if (words[i].substr(0, prefix.size()) == prefix) {
            results.push_back(words[i]);
        } else break;
    }

    if (results.empty()) {
        cout << "No matches found\n";
        return;
    }

    // Sort by frequency (descending)
    sort(results.begin(), results.end(), [](string a, string b) {
        return freq[a] > freq[b];
    });

    cout << "Suggestions:\n";

    int limit = min(3, (int)results.size());
    for (int i = 0; i < limit; i++) {
        cout << results[i] << " (searched " << freq[results[i]] << " times)\n";
    }

    // Increase frequency of top result
    freq[results[0]]++;
}

int main() {
    cout << "Smart Search Autocomplete System\n";
    cout << "--------------------------------\n";

    // Initial data
    addWord("apple");
    addWord("app");
    addWord("april");
    addWord("bat");
    addWord("ball");
    addWord("banana");

    sort(words.begin(), words.end());

    int choice;
    string input;

    while (true) {
        cout << "\nChoose an option:\n";
        cout << "1. Add Word\n";
        cout << "2. Search\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        if (choice == 1) {
            cout << "Enter word: ";
            cin >> input;
            addWord(input);
            sort(words.begin(), words.end());
        }
        else if (choice == 2) {
            cout << "Enter prefix: ";
            cin >> input;
            searchPrefix(input);
        }
        else if (choice == 3) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}