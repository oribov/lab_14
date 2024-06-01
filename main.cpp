\\ created by Ulugbek Oribov


#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>
#include <unordered_map>
#include <string>
#include <set>
#include <unordered_set>
#include <random>
#include <ctime>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;
void outputMap(const map<int, double>& myMap) {
 for (const auto& pair : myMap) {
 cout << pair.first << ": " << pair.second << endl;
 }
}
void displayPairs(const unordered_map<string, int>& myMap) {
 cout << "Pairs in the map:\n";
 for (const auto& pair : myMap) {
 cout << pair.first << ": " << pair.second << endl;
 }
}
void show(const set<int>& s) {
 cout << "Elements in sorted order:";
 for (auto it = s.begin(); it != s.end(); ++it) {
 cout << " " << *it;
 }
 cout << endl;
}
void show(const unordered_set<int>& s) {
 cout << "Elements:";
 for (auto it = s.begin(); it != s.end(); ++it) {
 cout << " " << *it;
 }
 cout << endl;
}
void show(const multiset<int>& s) {
 cout << "Elements:";
 for (auto it = s.begin(); it != s.end(); ++it) {
 cout << " " << *it;
 }
 cout << endl;
}
bool isSymmetric(const vector<int>& nums) {
 int n = nums.size();
 if (n == 0) return false;
 // Sort the numbers
 vector<int> sorted_nums = nums;
 sort(sorted_nums.begin(), sorted_nums.end());
 // Check if the sequence is symmetric
 for (int i = 0; i < n; ++i) {
 if (sorted_nums[i] % 10 != sorted_nums[n - 1 - i] % 10) {
 return false;
 }
 }
 return true;
}
void displayQueue(queue<int> q) {
 cout << "Elements in the queue:";
 while (!q.empty()) {
 cout << " " << q.front();
 q.pop();
 }
 cout << endl;
}
void clearQueue(queue<int>& q) {
 while (!q.empty()) {
 q.pop();
 }
}
int main() {
 std::cout<<"Problem_1"<<std::endl;
 std::map<int, int> m;
 // Insert key-value pairs
 m.insert({1, 1});
 m.insert({2, 4});
 m.insert({3, 9});
 m.insert({4, 16});
 m.insert({5, 25});
 // Print the contents of the map
 std::cout << "Contents of the map:" << std::endl;
 for (const auto& pair : m) {
 std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
 }
 std::cout<<"Problem_2"<<std::endl;
 map<int, string> competitionResults;
 vector<pair<int, string>> students = {{74, "Mike"}, {76, "Elena"}, {93, "David"},
{70, "George"}, {89, "Indira"}};
 // Sort students based on their grades
 sort(students.begin(), students.end(), greater<pair<int, string>>());
 // Store students' places and names in the map
 for (size_t i = 0; i < students.size(); ++i) {
 competitionResults[i + 1] = students[i].second;
 }
 // Output the results
 for (const auto& result : competitionResults) {
 cout << result.first << " place is " << result.second << ".\n";
 }
 std::cout<<"Problem_3"<<std::endl;
 // Create a map to store uppercase letters and their positions
 map<char, int> alphabetPositions;
 // Populate the map
 for (char letter = 'A'; letter <= 'Z'; ++letter) {
 alphabetPositions[letter] = letter - 'A' + 1;
 }
 // Prompt the user to input a letter
 cout << "Enter an uppercase letter: ";
 char inputLetter;
 cin >> inputLetter;
 // Convert the input letter to uppercase if it's lowercase
 inputLetter = toupper(inputLetter);
 // Check if the input letter exists in the map
 if (alphabetPositions.find(inputLetter) != alphabetPositions.end()) {
 // Print the position of the input letter
 cout << "Position of " << inputLetter << " is " <<
alphabetPositions[inputLetter] << endl;
 } else {
 cout << "Invalid input. Please enter an uppercase letter." << endl;
 }
 std::cout<<"Problem_4"<<std::endl;
 // 1. Create a map with the given pairs
 map<int, double> myMap = {{4, 7.5}, {25, 6.01}, {-9, 3.2}, {12, 5.16}};
 // 2. Output each pair of the map
 cout << "Original map:\n";
 outputMap(myMap);
 // 3. Insert a new pair (3, 3.75) and display resulting map
 myMap.insert(make_pair(3, 3.75));
 cout << "\nMap after inserting (3, 3.75):\n";
 outputMap(myMap);
 // 4. Insert a new pair (-10, 4.3) and display resulting map
 myMap.insert(make_pair(-10, 4.3));
 cout << "\nMap after inserting (-10, 4.3):\n";
 outputMap(myMap);
 // 5. Using method .find(), find key 12, store result inside iterator it and print
the value
 auto it = myMap.find(12);
 if (it != myMap.end()) {
 cout << "\nThe value corresponding to key 12 is: " << it->second << endl;
 } else {
 cout << "\nKey 12 not found in the map.\n";
 }
 // 6. Using the same iterator, delete pair with key 12 and print resulting map
 if (it != myMap.end()) {
 myMap.erase(it);
 cout << "\nMap after deleting pair with key 12:\n";
 outputMap(myMap);
 }
 // 7. Modify a value whose key is -9 to 4.44 and print resulting map
 it = myMap.find(-9);
 if (it != myMap.end()) {
 it->second = 4.44;
 cout << "\nMap after modifying value with key -9 to 4.44:\n";
 outputMap(myMap);
 }
 std::cout<<"Problem_5"<<std::endl;
 // 1. Create an unordered map with the given pairs
 unordered_map<string, int> myMap1 = {{"Earth", 3}, {"Mercury", 1}, {"Venus", 2}};
 // 2. Display all pairs of the map
 displayPairs(myMap1);
 // 3. Insert a pair ("Mars", 4) into the beginning and display the result
 myMap1.insert(myMap1.begin(), make_pair("Mars", 4));
 cout << "\nMap after inserting ('Mars', 4) into the beginning:\n";
 displayPairs(myMap1);
 // 4. Insert a pair ("Saturn", 6) into position 3 and then insert ("Neptune", 8)
into the same position. Display the result.
 auto it1 = myMap.begin();
 advance(it1, 2); // Move iterator to position 3
 myMap.emplace_hint(it1, "Saturn", 6);
 myMap.emplace_hint(it1, "Neptune", 8);
 cout << "\nMap after inserting ('Saturn', 6) and ('Neptune', 8) into position
3:\n";
 displayPairs(myMap1);
 // 5. Display the size of the map
 cout << "\nSize of the map: " << myMap1.size() << endl;
 // 6. Delete an element with key "Venus" and display resulting map
 myMap.erase("Venus");
 cout << "\nMap after deleting element with key 'Venus':\n";
 displayPairs(myMap1);
 std::cout<<"Problem_6"<<std::endl;
 // 1. Create a multimap with the given pairs
 multimap<int, int> myMultiMap = {{100, 3}, {150, 4}, {100, 90}};
 // 2. Using method .count(), print how many keys are equal to 100
 cout << "Number of keys equal to 100: " << myMultiMap.count(100) << endl;
 // 3. Insert the following pairs
 myMultiMap.insert({200, 32});
 myMultiMap.insert({100, -12});
 myMultiMap.insert({90, 45});
 // 4. Find the upper bound of key 100 and store result inside iterator variable
 auto it2 = myMultiMap.upper_bound(100);
 // 5. Using iterator, print keys and values of next two elements that are at upper
bound
 cout << "Keys and values at upper bound of key 100:\n";
 for (int i = 0; i < 2 && it2 != myMultiMap.end(); ++i, ++it2) {
 cout << "Key: " << it2->first << ", Value: " << it2->second << endl;
 }
 // 6. Using methods .find() and .erase(), delete elements where key is 100
 auto pairToDelete = myMultiMap.find(100);
 if (pairToDelete != myMultiMap.end()) {
 myMultiMap.erase(pairToDelete);
 }
 // Display resulting map
 cout << "\nResulting map after deleting elements with key 100:\n";
 for (const auto& pair : myMultiMap) {
 cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
 }
 std::cout<<"Problem_7"<<std::endl;
 int numUsers;
 cout << "Enter the number of users who want to register: ";
 cin >> numUsers;
 unordered_map<string, int> registeredUsers;
 for (int i = 0; i < numUsers; ++i) {
 string name;
 cin >> name;
 // Check if the name already exists
 if (registeredUsers.find(name) == registeredUsers.end()) {
 // If the name is new, store it and print "OK"
 registeredUsers[name] = 1;
 cout << "OK " << name << endl;
 } else {
 // If the name already exists, add a digit to make it unique
 int count = registeredUsers[name]++;
 cout << name << count << endl;
 }
 }
 std::cout<<"Problem_8"<<std::endl;
 int n;
 cout << "Enter the number of values in the sequence: ";
 cin >> n;
 unordered_map<int, int> occurrences;
 // Input the sequence
 for (int i = 0; i < n; ++i) {
 int num;
 cin >> num;
 occurrences[num]++;
 }
 // Check if the sequence is good
 bool isGood = true;
 for (const auto& pair : occurrences) {
 if (pair.second != pair.first) {
 isGood = false;
 break;
 }
 }
 // Output the result
 if (isGood) {
 cout << "Good sequence" << endl;
 } else {
 cout << "Not a good sequence" << endl;
 }
 std::cout<<"Problem_9"<<std::endl;
 // Initialize the set and insert values
 set<int> s;
 s.insert(5);
 s.insert(39);
 s.insert(10);
 s.insert(64);
 s.insert(82);
 s.insert(35);
 s.insert(10); // Duplicate, won't be inserted
 s.insert(54);
 // Print all elements in sorted order
 show(s);
 std::cout<<"Problem_10"<<std::endl;
 // Initialize the unordered set and insert values
 unordered_set<int> s1;
 s1.insert(5);
 s1.insert(39);
 s1.insert(10);
 s1.insert(64);
 s1.insert(82);
 s1.insert(35);
 s1.insert(10); // Duplicate, won't be inserted
 s1.insert(54);
 // Print all elements
 show(s1);
 std::cout<<"Problem_11"<<std::endl;
 multiset<int> s2;
 s2.insert(5);
 s2.insert(39);
 s2.insert(10);
 s2.insert(64);
 s2.insert(82);
 s2.insert(35);
 s2.insert(10); // Duplicate
 s2.insert(54);
 // Print all elements
 cout << "Original elements:\n";
 show(s2);
 // Erase elements from 10 to before 54
 auto it_start = s2.find(10);
 auto it_end = s2.find(54);
 if (it_start != s2.end() && it_end != s2.end()) {
 s2.erase(it_start, it_end);
 }
 // Print all elements after removal
 cout << "\nElements after removing elements from 10 to before 54:\n";
 show(s2);
 std::cout<<"Problem_12"<<std::endl;
 // Seed the random number generator
 srand(time(nullptr));
 // Generate 10 random integer values in the range [11, 20] and store them in a
multiset
 multiset<int> mySet;
 for (int i = 0; i < 10; ++i) {
 int randomNumber = rand() % 10 + 11; // Generates a random number in the range
[11, 20]
 mySet.insert(randomNumber);
 }
 // Output the multiset
 cout << "Multiset: ";
 for (const auto& num : mySet) {
 cout << num << " ";
 }
 cout << endl;
 // Prompt the user to input a number from the same range
 int inputNum;
 cout << "Enter a number from 11 to 20: ";
 cin >> inputNum;
 // Check if the input number exists in the multiset
 auto it3 = mySet.find(inputNum);
 if (it3 != mySet.end()) {
 cout << "YES" << endl;
 } else {
 cout << "Number not found in multiset" << endl;
 }
 std::cout<<"Problem_13"<<std::endl;
 int size;
 cout << "Enter the size of the sets: ";
 cin >> size;
 set<int> set1, set2;
 cout << "Enter elements of set 1: ";
 for (int i = 0; i < size; ++i) {
 int num;
 cin >> num;
 set1.insert(num);
 }
 cout << "Enter elements of set 2: ";
 for (int i = 0; i < size; ++i) {
 int num;
 cin >> num;
 set2.insert(num);
 }
 // Create sets for union, intersection, and difference
 set<int> unionSet, intersectionSet, differenceSet;
 // Union
 set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(unionSet,
unionSet.begin()));
 // Intersection
 set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
inserter(intersectionSet, intersectionSet.begin()));
 // Difference (elements in set1 but not in set2)
 set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(),
inserter(differenceSet, differenceSet.begin()));
 // Output the results
 cout << "Union=";
 for (int num : unionSet) {
 cout << num << " ";
 }
 cout << "Intersection=";
 for (int num : intersectionSet) {
 cout << num << " ";
 }
 cout << "Difference=";
 for (int num : differenceSet) {
 cout << num << " ";
 }
 cout << endl;
 std::cout<<"Problem_14"<<std::endl;
 int n1;
 cout << "Enter the size of the vector: ";
 cin >> n1;
 vector<int> nums(n1);
 cout << "Enter the elements of the vector: ";
 for (int i = 0; i < n1; ++i) {
 cin >> nums[i];
 }
 // Remove duplicates using a set
 set<int> uniqueNums(nums.begin(), nums.end());
 // Rewrite the vector without duplicates
 nums.assign(uniqueNums.begin(), uniqueNums.end());
 // Print resulting vector and its size
 cout << "Resulting vector:";
 for (int num : nums) {
 cout << " " << num;
 }
 cout << endl;
 cout << "Size of the resulting vector: " << nums.size() << endl;
 std::cout<<"Problem_15"<<std::endl;
 string S;
 int q;
 cout << "Enter the string S: ";
 cin >> S;
 cout << "Enter the number of queries: ";
 cin >> q;
 while (q--) {
 int i, j, k;
 cout << "Enter query (i, j, k): ";
 cin >> i >> j >> k;
 // Adjust i and j to 0-based index
 i--;
 j--;
 // Extract the substring
 string sub = S.substr(i, j - i + 1);
 // Sort the substring in the required order
 if (k == 0) {
 sort(sub.begin(), sub.end(), greater<char>());
 } else {
 sort(sub.begin(), sub.end());
 }
 // Replace the substring in the original string
 S.replace(i, j - i + 1, sub);
 }
 cout << "Final string after applying the queries: " << S << endl;
 std::cout<<"Problem_16"<<std::endl;
 int n2;
 cout << "Enter the number of elements in the sequence: ";
 cin >> n2;
 vector<int> nums2(n);
 cout << "Enter the sequence: ";
 for (int i = 0; i < n; ++i) {
 cin >> nums2[i];
 }
 // Check if the sequence is symmetric
 if (isSymmetric(nums2)) {
 cout << "Symmetric ";
 } else {
 cout << "Not symmetric ";
 }
 // Sort and print the numbers
 sort(nums2.begin(), nums2.end());
 cout << "Sorted sequence:";
 for (int num2 : nums2) {
 cout << " " << num2;
 }
 cout << endl;
 std::cout<<"Problem_17"<<std::endl;
 // 1. Input a series of integers and push them inside the queue
 queue<int> q1;
 cout << "Enter a series of integers (-1 to end): ";
 int num;
 while (true) {
 cin >> num;
 if (num == -1) {
 break;
 }
 q1.push(num);
 }
 // 2. Print the size of queue
 cout << "Size of the queue: " << q1.size() << endl;
 // 3. Display the values that are at front and at back
 if (!q1.empty()) {
 cout << "Front element: " << q1.front() << endl;
 cout << "Back element: " << q1.back() << endl;
 } else {
 cout << "Queue is empty." << endl;
 }
 // 4. Display all elements in the queue
 displayQueue(q1);
 // 5. Delete all elements in the queue
 clearQueue(q1);
 // Print the size of the queue after clearing
 cout << "Size of the queue after clearing: " << q1.size() << endl;
 std::cout<<"Problem_18"<<std::endl;
 // 1. Push numbers into a stack
 stack<int> myStack;
 myStack.push(43);
 myStack.push(90);
 myStack.push(100);
 myStack.push(30);
 myStack.push(28);
 myStack.push(1);
 myStack.push(34);
 // 2. Print the size of stack
 cout << "Size of the stack: " << myStack.size() << endl;
 // 3. Display the value at top
 if (!myStack.empty()) {
 cout << "Value at top: " << myStack.top() << endl;
 } else {
 cout << "Stack is empty." << endl;
 }
 // 4. Delete required elements of stack and print the size
 while (!myStack.empty() && myStack.top() != 30) {
 myStack.pop();
 }
 cout << "Size of the stack after deleting required elements: " << myStack.size()
<< endl;
 return 0;
}
