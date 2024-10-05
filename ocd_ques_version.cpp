#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// Version Control System class to manage document revisions
class VersionControlSystem {
private:
    unordered_map<int, string> revisions;  // Store revisions in a hash map (revision_id -> content)
    int latest_revision_id;  // Store the latest revision ID

public:
    // Constructor initializes the latest revision ID to -1 (indicating no revisions yet)
    VersionControlSystem() : latest_revision_id(-1) {}

    // Add a new revision with unique identifier
    void addRevision(int revision_id, const string& content) {
        if (revisions.find(revision_id) != revisions.end()) {
            cout << "Revision with ID " << revision_id << " already exists." << endl;
            return;
        }
        revisions[revision_id] = content;
        if (revision_id > latest_revision_id) {
            latest_revision_id = revision_id;  // Update the latest revision ID
        }
        cout << "Added: Revision " << revision_id << ": " << content << endl;
    }

    // Retrieve a specific revision by its ID
    string getRevision(int revision_id) {
        if (revisions.find(revision_id) == revisions.end()) {
            return "Revision with ID " + to_string(revision_id) + " does not exist.";
        }
        return revisions[revision_id];
    }

    // Retrieve the most recent revision
    string getLatestRevision() {
        if (latest_revision_id == -1) {
            return "No revisions available.";
        }
        return revisions[latest_revision_id];
    }

    // Retrieve all revisions sorted by their revision IDs
    vector<pair<int, string>> getAllRevisions() {
        vector<pair<int, string>> all_revisions(revisions.begin(), revisions.end());

        // Sort revisions by revision ID
        sort(all_revisions.begin(), all_revisions.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
            return a.first < b.first;
        });

        return all_revisions;
    }
};

// Testing the optimized version control system
void testVersionControl() {
    VersionControlSystem vcs;

    // Add some revisions
    vcs.addRevision(1, "First version of the document.");
    vcs.addRevision(2, "Second version with updates.");
    vcs.addRevision(3, "Third version, minor fixes.");

    // Retrieve specific revision
    cout << "\nRetrieve Revision 2: " << vcs.getRevision(2) << endl;

    // Get the latest revision
    cout << "\nLatest Revision: " << vcs.getLatestRevision() << endl;

    // Get all revisions
    cout << "\nAll Revisions:" << endl;
    vector<pair<int, string>> all_revisions = vcs.getAllRevisions();
    for (const auto& revision : all_revisions) {
        cout << "Revision " << revision.first << ": " << revision.second << endl;
    }
}

int main() {
    // Run the test
    testVersionControl();
    return 0;
}
