#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"
#include <unordered_map>

using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        string ret;
        size = formula.length();
        unordered_map<string, int> atomCount;
        int pos = 0;
        handleParenthese(formula, pos, atomCount);
        vector<string> atoms;
        for (auto atom : atomCount) {
            atoms.push_back(atom.first);
        }
        sort(atoms.begin(), atoms.end());
        for (auto atom : atoms) {
            ret.append(atom);
            if (atomCount[atom] > 1) {
                ret.append(to_string(atomCount[atom]));
            }
        }
        return ret;
	}

private:
    void handleParenthese(const string& formula,
            int& pos,
            unordered_map<string, int>& atomCount) {
        int startPos, numPos;
        // 0 start, 1 new Atom, 2 parenthese atom
        int lastAtom = 0;
        unordered_map<string, int> localAtomCount;
        while ((pos < size) &&
                (formula[pos] != ')')) {
            if (formula[pos] == '(') {
                switch(lastAtom) {
                  case 1:
                    atomCount[formula.substr(startPos, pos - startPos)]++; break;
                  default:
                    for (auto atom : localAtomCount) {
                        atomCount[atom.first] += atom.second;
                    }
                    localAtomCount.clear();
                }
                ++pos;
                handleParenthese(formula, pos, localAtomCount);
                lastAtom = 2;
            } else if ((formula[pos] >= 'A') && (formula[pos] <= 'Z')) {
                switch(lastAtom) {
                  case 0:
                    startPos = pos; lastAtom = 1; break;
                  default:
                    atomCount[formula.substr(startPos, pos - startPos)]++; startPos = pos;
                }
                ++pos;
            } else if ((formula[pos] >= 'a') && (formula[pos] <= 'z')) {
                ++pos;
            } else if ((formula[pos] >= '1') && (formula[pos] <= '9')) {
                int count = formula[pos] - '0';
                numPos = pos + 1;
                while ((numPos < size) &&
                        (formula[numPos] >= '0') &&
                        (formula[numPos] <= '9')) {
                    count = count * 10 + (formula[numPos] - '0');
                    ++numPos;
                }
                switch(lastAtom) {
                  case 1:
                    atomCount[formula.substr(startPos, pos - startPos)] += count;
                    lastAtom = 0;
                    break;
                  default:
                    for (auto atom : localAtomCount) {
                        atomCount[atom.first] += atom.second * count;
                    }
                    localAtomCount.clear();
                    lastAtom = 0;
                }
                pos = numPos;
            }
        }

        switch(lastAtom) {
          case 1:
            atomCount[formula.substr(startPos, pos - startPos)]++;
            break;
          default:
            for (auto atom : localAtomCount) {
                atomCount[atom.first] += atom.second;
            }
            localAtomCount.clear();
        }

        if (pos < formula.length()) {
            ++pos;
        }
    }

private:
    int size;
};

int main(int argc, char* argv[])
{
    // input
    string str;
    Input(str);

    // solution
    Solution solution;
	string ret = solution.countOfAtoms(str);

    // output
    Output(ret);

    return 0;
}
