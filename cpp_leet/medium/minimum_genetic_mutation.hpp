#pragma once

#include "../imports.hpp"

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> spankBank(bank.begin(), bank.end());
        unordered_set<string> visited;
        queue<string> geneQueue;
        int iterations = 0;
        geneQueue.push(startGene);
        while (!geneQueue.empty()) {
            int size = geneQueue.size();
            for (int i = 0; i < size; ++i) {
                string curGene = geneQueue.front();
                geneQueue.pop();
                visited.insert(curGene);
                if (curGene == endGene) {
                    return iterations;
                }
                for (int j = 0; j < 8; ++j) {
                    char letter = curGene[j];
                    curGene[j] = 'A';
                    if (spankBank.count(curGene) && !visited.count(curGene)) {
                        geneQueue.push(curGene);
                    } 
                    curGene[j] = 'T';
                    if (spankBank.count(curGene) && !visited.count(curGene)) {
                        geneQueue.push(curGene);
                    } 
                    curGene[j] = 'G';
                    if (spankBank.count(curGene) && !visited.count(curGene)) {
                        geneQueue.push(curGene);
                    } 
                    curGene[j] = 'C';
                    if (spankBank.count(curGene) && !visited.count(curGene)) {
                        geneQueue.push(curGene);
                    }
                    curGene[j] = letter;
                }
            }
            ++iterations;
        }
        return -1;
    }
}; 