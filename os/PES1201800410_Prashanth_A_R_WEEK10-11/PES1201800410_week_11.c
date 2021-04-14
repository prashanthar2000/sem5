#include <stdio.h>

int check(int k, int *arr, int n)
{
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == k)
			flag = 1;
	}
	if (flag == 1 && k == -1)
		return -1;
	else
		return flag;
}

int main()
{
	int n;
	printf("The length of the reference String --");
	scanf("%d", &n);
	
	int ref[n];
	printf("Enter the reference string -- ");
	for (int i = 0; i < n; i++)
	{
		scanf(" %d", &ref[i]);
	}

	int frame_size;
	printf("Enter the number of frames --");
	scanf("%d", &frame_size);

	int frames[frame_size];
	for (int i = 0; i < frame_size; i++)
	{
		frames[i] = -1;
	}
	int count = 0 ; 
	int flag = 0 ; 
	int temp[n] ; 
	int pos = 0 ; 
	printf("\nThe Page Replacement Process is --\n");
	for (int i = 0; i < n; i++)
	{
		if (check(ref[i], frames, frame_size) == 1)
		{
			printf("%d %d %d\n", frames[0], frames[1], frames[2]);
		}
		else
		{
			++count;
			flag = check(-1, frames, frame_size);
			if (flag == -1)
			{
				for (int j = 0; j < frame_size; j++)
				{
					if (frames[j] == -1)
					{
						frames[j] = ref[i];
						break;
					}
				}
			}
			else
			{
				for (int j = 0; j < frame_size; j++)
					temp[j] = 0;

				for (int j = i - 1, k = 1; k <= frame_size - 1; k++, j--)
				{
					for (int l = 0; l < frame_size; l++)
					{
						if (frames[l] == ref[j])
						{
							temp[l] = 1;
						}
					}
				}
				for (int j = 0; j < frame_size; j++)
				{
					if (temp[j] == 0)
						pos = j;
				}
				frames[pos] = ref[i];
			}
			printf("%d %d %d PF No.-- %d\n", frames[0], frames[1], frames[2], count);
		}
	}
	printf(" The number of Page faults using LRU is  %d\n", count);
}
