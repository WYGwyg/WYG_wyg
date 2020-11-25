class Solution {
public:
	/**
	* ���ֲ���
	* @param n int���� ���鳤��
	* @param v int���� ����ֵ
	* @param a int����vector ��������
	* @return int����
	*/
	int upper_bound_(int n, int v, vector<int>& a) {
		// write code here
		int left = 0;
		int right = n - 1;
		while (left < right)
		{
			int mid = left + (right - left) / 2;
			if (a[mid] >= v)
			{
				if (mid == 0 || a[mid - 1] < v)
				{
					return mid + 1;
				}
				else
				{
					right = mid;
				}
			}
			else
			{
				left = mid + 1;
			}
		}
		return n + 1;
	}
};