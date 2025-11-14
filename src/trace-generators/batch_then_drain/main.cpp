//
// Created by Ali Kooshesh on 11/1/25.
//

#include <iostream>
#include <fstream>

#include "../../../utils/TraceConfig.hpp"
#include<random>
#include<iomanip>

void generateTrace(const unsigned seed,
    const std::size_t n,
    TraceConfig &config,
    std::uniform_int_distribution<int> &dist,
    std::mt19937& gen ) {

    // create and open the output file name
    auto outputFileName = config.makeTraceFileName(seed, n);
    std::cout << "File name: " << outputFileName << std::endl;
    std::ofstream out(outputFileName.c_str());
    if (!out.is_open()) {
        std::cerr << "Failed to open file " << outputFileName << std::endl;
        exit(1);
    }
    out << config.profileName << " " << n << " " << seed << std::endl;

    // Generate N inserts.
    unsigned id = 0;        // id serves as a tiebreaker. Don't use the loop variable for
                            // this purpose because we have multiple loops and could
                            // accidentally generate duplicate IDs.
    int spaceBeforeNumber = 10;
    for (unsigned i = 0; i < n; ++i) {
        out << "I " << std::setw(spaceBeforeNumber) << dist(gen) << std::setw(spaceBeforeNumber) << id++ << "\n";
    }

    // we are not doing this. this was for huffman where we extract twice and then insert their combination
    // we just extract_min
    for (unsigned i = 0; i < n; ++i) {
        out << "E" << "\n"; // Just the E's are required to the extract_min
    }
    out.close();
}

/*
 // Don't need this code cause we aren't using generating for huffman tree, we just need to use n
int choose_key_upper_bound(unsigned int N) {
    // You can change the upperbound to
    // see how that effects the frequency (key)
    // that get generated.

    if (N <= 50)   // this is for the benefit of our small data set.
        return 3;
    if (N <= (1u << 12))
        return 12;
    if (N <= (1u << 15))
        return 32;
    if (N <= (1u << 18))
        return 64;
    return 128; // for 2^19 and 2^20
}
*/

int main() {

    // TraceConfig provides pre-configured values such as N and seed
    TraceConfig config( std::string("batch_then_drain")); //updated the file name
    for (auto seed: config.seeds) {  // currently, we are using one seed only.
        std::mt19937 rng(seed);   // create a random-number generator using "seed"

        for (auto n: config.Ns) {

            // not sure if I need this
            const unsigned key_min = 1, key_max = 1u << 20; // 2^20 or 1048576
            std::uniform_int_distribution<int> dist(key_min, key_max);

            generateTrace(seed, n, config, dist, rng);
        }

    }

    return 0;
}