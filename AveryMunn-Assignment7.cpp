#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>

//using namspace
using namespace std;

int main() {
    // Open the file for reading
    ifstream file("movieRatings.txt");
    if (!file) {
        cerr << "Failed to open file" << endl;
        return 1;
    }

    // Read the first line to get the number of ratings
    int num_ratings;
    file >> num_ratings;

    // Initialize the movie map to store the number of reviews and the sum of ratings
    map<string, pair<int, int>> movie_map;

    // Loop through the rest of the lines in the file
    for (int i = 0; i < num_ratings; i++) {
        // Read the movie name and rating
        string movie_name;
        int rating;
        file >> ws;  // skip whitespace
        getline(file, movie_name);
        file >> rating;

        // Update the movie map with the new rating
        if (movie_map.find(movie_name) != movie_map.end()) {
            movie_map[movie_name].first++;
            movie_map[movie_name].second += rating;
        }
        else {
            movie_map[movie_name] = { 1, rating };
        }
    }

    // Loop through the movie map and output the results
    for (auto it = movie_map.begin(); it != movie_map.end(); it++) {
        string movie_name = it->first;
        int num_reviews = it->second.first;
        int total_rating = it->second.second;
        double avg_rating = static_cast<double>(total_rating) / num_reviews;
        cout << movie_name << ": " << num_reviews << " reviews, average of " << avg_rating << std::setprecision(2) << " / 5" << endl;
    }

    return 0;
}
