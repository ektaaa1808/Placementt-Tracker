#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Question {
    string name;
    string topic;
    string difficulty;
};

vector<Question> questions;
void loadData() {
    ifstream file("data.txt");
    Question q;

    while (file >> q.name >> q.topic >> q.difficulty) {
        questions.push_back(q);
    }
    file.close();
}
void saveAll() {
    ofstream file("data.txt");
    for (auto q : questions) {
        file << q.name << " " << q.topic << " " << q.difficulty << endl;
    }
    file.close();
}
void addQuestion() {
    Question q;
    cout << "Enter question name: ";
    cin >> q.name;

    cout << "Enter topic (Array/DP/Graph/String): ";
    cin >> q.topic;

    cout << "Enter difficulty (Easy/Medium/Hard): ";
    cin >> q.difficulty;

    questions.push_back(q);

    ofstream file("data.txt", ios::app);
    file << q.name << " " << q.topic << " " << q.difficulty << endl;
    file.close();

    cout << "Added successfully!\n";
}
void displayAll() {
    if (questions.empty()) {
        cout << "No data found\n";
        return;
    }

    cout << "\n--- All Questions ---\n";
    for (auto q : questions) {
        cout << q.name << " | " << q.topic << " | " << q.difficulty << endl;
    }
}
void showStats() {
    int easy = 0, medium = 0, hard = 0;

    for (auto q : questions) {
        if (q.difficulty == "Easy") easy++;
        else if (q.difficulty == "Medium") medium++;
        else if (q.difficulty == "Hard") hard++;
    }

    cout << "\n--- Stats ---\n";
    cout << "Easy: " << easy << endl;
    cout << "Medium: " << medium << endl;
    cout << "Hard: " << hard << endl;
    cout << "Total: " << questions.size() << endl;
}
void topicAnalysis() {
    int array = 0, dp = 0, graph = 0, stringT = 0;

    for (auto q : questions) {
        if (q.topic == "Array") array++;
        else if (q.topic == "DP") dp++;
        else if (q.topic == "Graph") graph++;
        else if (q.topic == "String") stringT++;
    }

    cout << "\n--- Topic Analysis ---\n";
    cout << "Array: " << array << endl;
    cout << "DP: " << dp << endl;
    cout << "Graph: " << graph << endl;
    cout << "String: " << stringT << endl;
}
void weakTopic() {
    int array = 0, dp = 0, graph = 0, stringT = 0;

    for (auto q : questions) {
        if (q.topic == "Array") array++;
        else if (q.topic == "DP") dp++;
        else if (q.topic == "Graph") graph++;
        else if (q.topic == "String") stringT++;
    }

    int minVal = array;
    string weak = "Array";

    if (dp < minVal) { minVal = dp; weak = "DP"; }
    if (graph < minVal) { minVal = graph; weak = "Graph"; }
    if (stringT < minVal) { minVal = stringT; weak = "String"; }

    cout << "\nWeakest Topic: " << weak << endl;
}

int main() {
    int choice;

    loadData();

    while (true) {
        cout << "\n===== PLACEMENT TRACKER =====\n";
        cout << "1. Add Question\n";
        cout << "2. View All\n";
        cout << "3. Show Stats\n";
        cout << "4. Topic Analysis\n";
        cout << "5. Weak Topic\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        if (choice == 1) addQuestion();
        else if (choice == 2) displayAll();
        else if (choice == 3) showStats();
        else if (choice == 4) topicAnalysis();
        else if (choice == 5) weakTopic();
        else if (choice == 6) break;
        else cout << "Invalid choice\n";
    }

    return 0;
}