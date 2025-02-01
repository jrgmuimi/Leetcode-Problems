/* Used Ashish Manoj Chourasia's Explanation: From the division algorithm, any number z can be expressed in the form z = q * d + r
Where q is the quotient, d is the divisor, and r is the remainder. Since we are taking the floor, we can safely disregard r.
Any integer can additionally be broken up into powers of 2, take for example a dividend of 58 and divisor of 5. 
58 = 11 * 5 + 3 = (2^3 + 2^1 + 2^0) * 5 + 3 = 5(2^3) + 5(2^1) + 5(2^0) + 3. So, to solve this,
we use this principle and find the largest power first by left shifting the divisor just before its > the dividend.
We take the value of the shifts (2^shifts) and add it to the quotient, then we subtract the shifted divisor from the dividend
and repeat the process: 5<<3 = 40, but 5<<4 = 80, so we add (2^3) to the quotient, and repeat process with new dividend: 58-40 = 18,
5<<1 = 10, but 5<<2 = 20, so we add (2^1) to quotient and subtract 10 from 18 = 8. Finally, 5<<0 = 5, but 5<<1 = 10, so we add (2^0).
Since the dividend < divisor, we can stop since we've found the remainder, and the divisor can't go into the dividend anymore.
https://leetcode.com/problems/divide-two-integers/solutions/1516367/complete-thinking-process-intuitive-explanation-all-rules-followed-c-code/
*/

int divide(int dividend, int divisor) 
{ /* O(log[base 2]**2(dividend)) Time Complexity (Estimate), O(1) Space Complexity
Considering the input size is limited to the 32-bit signed integer range, the worst case I can imagine is if the dividend is INT_MAX and the
divisor is 1. In order for cpy or 1 in the code below to shift to INT_MIN, it has to shift 30 times which is 1073741824. It cant shift 31
because 2^31 = 2147483648 which is out of range of INT_MAX (2^31-1). Additionally, once INT_MAX is subtracted by 2^30, we get the same issue:
We have to use 2^29 and not 2^30, and so forth. So the number of loops/shifts are a summation from n = 0 to 30, resulting in ~465 loops.
Hence the O(log[base 2]**2(dividend)) Running Time. In summation: Outside Loop Runs log_2(INT_MAX) ~= 31 times, and inside loop runs 30 times
at beginning but decreases by 1 each outside loop. In worst case.
*/
    int dividIsNeg = (dividend < 0); // Check if the dividend or the divisor is negative
    int divisIsNeg = (divisor < 0); // Will reapply the sign at end

    long abs_divid = dividend;
    long abs_divis = divisor;

    if (dividIsNeg) { abs_divid = -abs_divid; } // Make positive if negative
    if (divisIsNeg) { abs_divis = -abs_divis; }

    long quotient = 0; // Store quotient we find

    while (abs_divid >= abs_divis) // From explanation above, keep subtracting 5*(powers of 2) from the dividend until dividend < divisor
    {
        int shift_ct = 0; // For 2^0
        long cpy = abs_divis; // Variable used to shift the divisor left while preserving original divisor

        while ((cpy<<1) <= abs_divid) // If we can shift the divisor left, while still being <= dividend, then do so
        {
            cpy <<= 1;
            shift_ct++;
        }

        quotient += (long)1 << shift_ct; // Once we've found a shift count and can no longer shift the divisor anymore, add (2^shift) to Q
        abs_divid-=cpy; // Subtract 5*(2^shift) from dividend and repeat process as listed in explanation above
    }

    if(dividIsNeg ^ divisIsNeg) { quotient = -quotient; } // Use XOR, if both are negative or both aren't negative, then don't apply negation

    if (quotient > INT_MAX) { return INT_MAX; } // As per instructions in the problem, if quotient is > INT_MAX or < INT_MIN, return MIN/MAX
    if (quotient < INT_MIN) { return INT_MIN; }

    return quotient;
}
