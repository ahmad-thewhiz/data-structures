// Problem: Design a dice() function that mimics a fair six-sided dice roll (1 to 6), without relying on any built-in random number generators (rand() or similar).

int dice() {
        int result = 0;

        // Generate a value between 0 and 7 using three tosses
        for (int i = 0; i < 3; i++) {
            result = (result << 1) | toss();
        }

        // Ensure the result is between 1 and 6
        while (result == 0 || result > 6) {
            result = 0;
            for (int i = 0; i < 3; i++) {
                result = (result << 1) | toss();
            }
        }

        return result;
    }
