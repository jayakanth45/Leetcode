class Solution {
public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        sort(0, nums.size() - 1, nums);
        return nums;
    }

private:
    void sort(int l, int r, std::vector<int>& nums) {
        if (l < r) {
            int mid = (l + r) / 2;
            sort(l, mid, nums);
            sort(mid + 1, r, nums);
            merge(l, mid, r, nums);
        }
    }

    void merge(int l, int mid, int r, std::vector<int>& nums) {
        int n1 = mid - l + 1;
        int n2 = r - mid;
        std::vector<int> L(n1);
        std::vector<int> R(n2);
        for (int i = 0; i < n1; i++) L[i] = nums[l + i];
        for (int j = 0; j < n2; j++) R[j] = nums[mid + 1 + j];
        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) nums[k] = L[i++];
            else nums[k] = R[j++];
            k++;
        }
        while (i < n1) nums[k++] = L[i++];
        while (j < n2) nums[k++] = R[j++];
    }
};