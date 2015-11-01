class Solution {
public:
    vector<int> mysort(vector<int>& x){ //non-descending order
        vector<int> arr = x;
        if(arr.size() == 1){
            return arr;
        }
        if(arr.size() == 2){
            if(arr[0]>arr[1]){
                int tmp = arr[0];
                arr[0] = arr[1];
                arr[1] = tmp;
            }
            return arr;
        }
        int midpoint = arr.size() / 2;
        vector<int> lo (arr.begin(),arr.begin() + midpoint);
        vector<int> hi (arr.begin() + midpoint, arr.end());
        lo = mysort(lo);
        hi = mysort(hi);
        vector<int> retval;
        retval.reserve(lo.size()+hi.size());
        int ptr1 = 0, ptr2 = 0;
        while(lo.size() > ptr1  && hi.size() > ptr2){
            if(lo[ptr1]<hi[ptr2]){
                retval.push_back((int)lo[ptr1]);
                ptr1++;
                if(ptr1 >= lo.size()){
                    retval.insert(retval.end(), hi.begin() + ptr2, hi.end());
                }//end if
            }else{
                retval.push_back((int)hi[ptr2]);
                ptr2++;
                if(ptr2 >= hi.size()){
                    retval.insert(retval.end(), lo.begin() + ptr1, lo.end());
                }//end if
            }//end if lo and hi
        }//end while
        return retval;
    }//end mysort

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> myvec;
        if(nums.size() <3) return myvec;
        if(nums.size() == 3){
            if(nums[0] + nums[1] + nums[2] == 0){
                myvec.push_back(mysort(nums));
                return myvec;
            }
        }
        vector<int> arr = mysort(nums);
        bool zero_flag = false;
        for(int i = 0; i< arr.size() - 2; i++){
            //if(arr[i] == arr[i+1] && arr[i] !=0 ) continue;
            if(i == 0 || arr[i] > arr[i-1]){
                if(zero_flag && arr[i] == 0) continue;
                int start = i + 1;
                int end = arr.size() - 1;
                int neg = arr[i] * -1;
                
                while (start < end){
                    if( arr[start] + arr[end] == neg){
                        vector<int> mycase;
                        if(arr[i] == 0 && !zero_flag){
                            zero_flag = true;
                        }
                        mycase.push_back(arr[i]);
                        mycase.push_back(arr[start]);
                        start ++;
                        mycase.push_back(arr[end]);
                        end -- ;
                        myvec.push_back(mycase);
                        mycase.clear();
                        while(start < end && arr[end] == arr[end + 1] ) end --;
                        while(start < end && arr[start] == arr[start - 1] ) start ++;
                        //end if main
                    }else if(arr[start] + arr[end] > neg){
                        end --;
                    }else{
                        start ++;
                    }
                    if(zero_flag) break;
                }//end while
            }//end if
        }//end for i

        if(myvec.size()>=2){
            for( int i = 0; i < myvec.size()-1; i++){
                if(myvec[i][0] == myvec[i+1][0] && myvec[i][1] == myvec[i+1][1] && myvec[i][2] == myvec[i+1][2]){
                    myvec.erase(myvec.begin() + i );
                }
            }
        }
        return myvec;
    }
};
