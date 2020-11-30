class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double res = 0;
        
        int totalSize = nums1.size() + nums2.size();
        
        if (totalSize > 0) {
            bool isOdd = totalSize % 2 == 1;
            double middleValue = 0;
            int nums1Size = nums1.size();
            int nums2Size = nums2.size();
            
            
            int startIndex = 0;
            
            startIndex = isOdd ? totalSize / 2 : totalSize / 2 - 1;
            
            int num1Index = 0;
            int num2Index = 0;
            
            for (int i = 1; i <= startIndex; ++i) {
                if (num1Index < nums1Size && num2Index < nums2Size) {
                    if (nums1[num1Index] <= nums2[num2Index]) {
                        num1Index++;
                    }
                    else {
                        num2Index++;
                    }
                }
                else if (num1Index == nums1Size) {
                    num2Index++;
                }
                else {
                    num1Index++;
                }
            }
            if (num1Index < nums1Size && num2Index < nums2Size) {
                if (nums1[num1Index] <= nums2[num2Index]) {
                    middleValue = nums1[num1Index++];
                }
                else {
                    middleValue = nums2[num2Index++];
                }
            }
            else if (num1Index == nums1Size) {
                middleValue = nums2[num2Index++];
            }
            else {
                middleValue = nums1[num1Index++];
            }
            
            if (!isOdd) {
                if (num1Index < nums1Size && num2Index < nums2Size) {
                    if (nums1[num1Index] <= nums2[num2Index]) {
                        middleValue += nums1[num1Index++];
                    }
                    else {
                        middleValue += nums2[num2Index++];
                    }
                }
                else if (num1Index == nums1Size) {
                    middleValue += nums2[num2Index++];
                }
                else {
                    middleValue += nums1[num1Index++];
                }
                middleValue /= 2.0;
            }
            
            res = middleValue;
        }
        return res;
    }
};
