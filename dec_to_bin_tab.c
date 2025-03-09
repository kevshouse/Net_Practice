#include <stdio.h>

void get_binary(int decimal, char *buffer) {
    // Converts decimal to 8-bit binary string
    for (int bit = 7; bit >= 0; bit--) {
        buffer[7 - bit] = (decimal >> bit) & 1 ? '1' : '0';
    }
    buffer[8] = '\0'; // Null-terminate the string
}

int main() {
    char bin_col1[9], bin_col2[9], bin_col3[9], bin_col4[9];
    
    // Header
    printf("Dec  Binary    Dec  Binary    Dec  Binary    Dec  Binary\n");
    printf("--------------------------------------------------------\n");
    
    // Print 64 rows (4 columns of 64 values each)
    for (int i = 0; i < 64; i++) {
        int num1 = i;
        int num2 = i + 64;
        int num3 = i + 128;
        int num4 = i + 192;
        
        // Convert decimals to binary strings
        get_binary(num1, bin_col1);
        get_binary(num2, bin_col2);
        get_binary(num3, bin_col3);
        get_binary(num4, bin_col4);
        
        // Print formatted row
        printf("%-4d %-8s  %-4d %-8s  %-4d %-8s  %-4d %-8s\n",
               num1, bin_col1,
               num2, bin_col2,
               num3, bin_col3,
               num4, bin_col4);
    }
    
    return 0;
}