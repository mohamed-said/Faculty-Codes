#include <iostream>
#include <cmath>

using namespace std;

// fuck
// still wrong answer
class FoxPlayingGame {
public:
	double theMax(int nA, int nB, int paramA, int paramB) {
		
		double score = 0;
		double scoreA = paramA / 1000.0;
		double scoreB = paramB / 1000.0;

		cout << scoreA << " " << scoreB << endl;

		if (scoreA > 0 && scoreB > 0.9) {
			score += (nA * scoreA);
			score *= (pow(scoreB, nB));
			return score;
		}
		
	//	cout << "case 2" << endl;
		if (scoreA > 0 && scoreB < 1) {
			if (paramB > 0) {
				score += (nA * scoreA);
	//			cout << "score so far = " << score << endl;
			} else if (scoreB < 0) {
				score += (nA * scoreA);
				if (nB % 2 == 1) {
					score *= (pow(abs(scoreB), --nB));
				} else {
					score *= (pow(abs(scoreB), nB));
				}
			}
			return score;
		}		
	
		if (scoreA < 1 && scoreB > 1) {
			return (nA * scoreA);
		}
		
		if (scoreA < 1 && scoreB < 1) {
			score += nA * scoreA; // negative number
			if (nB % 2 == 0) score *= pow(scoreB, --nB);
			else score *= pow(scoreB, nB);
			return score;
		}	
	}
};
