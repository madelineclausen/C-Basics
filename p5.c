void madd(int* a, int* b, int m, int n)
{
	for (int i=0; i<m; i++)
	{
		for (int j=0; j<n; j++)
		{
			*(a+(i*n)+j) = *(a+(i*n)+j) + *(b+(i*n)+j);
		}
	}

}
int main () {
	return 0;
}