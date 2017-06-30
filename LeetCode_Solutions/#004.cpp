// #004
//
// There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
//
// Example 1:
// nums1 = [1, 3]
// nums2 = [2]
//
// The median is 2.0
// Example 2:
// nums1 = [1, 2]
// nums2 = [3, 4]
//
// The median is (2 + 3)/2 = 2.5
//


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int i=0,j=0,total = nums1.size()+nums2.size();
        //cout<<total<<endl;
        int prev=0,curr=0;
        int half = ceil(total/2)+1;
        //cout<<half<<endl;
        if(nums1.size()==0){
            return (nums2.size()%2)?nums2[ceil((float)nums2.size()/2)-1]:(float)(nums2[(nums2.size()/2)-1]+nums2[(nums2.size())/2])/2;
        }
        else if(nums2.size()==0){
            return (nums1.size()%2)?nums1[ceil((float)nums1.size()/2)-1]:(float)(nums1[(nums1.size()/2)-1]+nums1[(nums1.size())/2])/2;
        }
        else{
        for(int k=0; k<half; k++){
            prev = curr;
            int v1 = (i<nums1.size())?nums1[i]:INT_MAX;
            int v2 = (j<nums2.size())?nums2[j]:INT_MAX;
            if(v2<v1){
                curr= v2;
                j+=1;
                //cout<<curr<<endl;
            }
            else{
                curr=v1;
                i+=1;
                //cout<<curr<<endl;
            }
        }
        cout<<"\n\n"<<curr<<"\n"<<prev<<endl;
        return (total%2)?curr:(float)(curr+prev)/2;
    }
    }
};
