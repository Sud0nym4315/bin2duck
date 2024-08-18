#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(const string& s, int chunk_size) {
    vector<string> chunks;
    for (size_t i = 0; i < s.length(); i += chunk_size) {
        chunks.push_back(s.substr(i, chunk_size));
    }
    return chunks;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " input_file output_file" << endl;
        return 1;
    }

    ifstream input_file(argv[1]);
    ofstream output_file(argv[2]);

    if (!input_file) {
        cerr << "Error opening input file" << endl;
        return 1;
    }

    if (!output_file) {
        cerr << "Error opening output file" << endl;
        return 1;
    }

    string base64_string((istreambuf_iterator<char>(input_file)), istreambuf_iterator<char>());
    input_file.close();

    //split b64 str into 50 char chunks
    vector<string> chunks = split(base64_string, 50);

    //is it better to append chunks to file via cli as a one-liner or incrementally?
    //for now, incrementally seems best
    for (const string& chunk : chunks) {
        output_file << "STRING " << chunk << " >> txt.b64" << endl; //standardize temp file name?
        output_file << "DELAY 350" << endl;
        output_file << "ENTER" << endl;
        output_file << "DELAY 350" << endl;
    }

    output_file.close();

    return 0;
}
