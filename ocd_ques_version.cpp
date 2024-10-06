#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class VersionControlSystem {
private:
    unordered_map<int, string> revisions;  
    int latest_revision_id;  

public:
    VersionControlSystem() : latest_revision_id(-1) {}

    void addRevision(int revision_id, const string& content) {
        if (revisions.find(revision_id) != revisions.end()) {
            cout << "Revision with ID " << revision_id << " already exists." << endl;
            return;
        }
        revisions[revision_id] = content;
        if (revision_id > latest_revision_id) {
            latest_revision_id = revision_id; 
        }
        cout << "Added: Revision " << revision_id << ": " << content << endl;
    }

    string getRevision(int revision_id) {
        if (revisions.find(revision_id) == revisions.end()) {
            return "Revision with ID " + to_string(revision_id) + " does not exist.";
        }
        return revisions[revision_id];
    }

    string getLatestRevision() {
        if (latest_revision_id == -1) {
            return "No revisions available.";
        }
        return revisions[latest_revision_id];
    }

    vector<pair<int, string>> getAllRevisions() {
        vector<pair<int, string>> all_revisions(revisions.begin(), revisions.end());

        sort(all_revisions.begin(), all_revisions.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
            return a.first < b.first;
        });

        return all_revisions;
    }
};

void testVersionControl() {
    VersionControlSystem vcs;

    vcs.addRevision(1, "First version of the document.");
    vcs.addRevision(2, "Second version with updates.");
    vcs.addRevision(3, "Third version, minor fixes.");

    cout << "\nRetrieve Revision 2: " << vcs.getRevision(2) << endl;

    cout << "\nLatest Revision: " << vcs.getLatestRevision() << endl;

    cout << "\nAll Revisions:" << endl;
    vector<pair<int, string>> all_revisions = vcs.getAllRevisions();
    for (const auto& revision : all_revisions) {
        cout << "Revision " << revision.first << ": " << revision.second << endl;
    }
}

int main() {
    testVersionControl();
    return 0;
}
