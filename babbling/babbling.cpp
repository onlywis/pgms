#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// babbling_len은 배열 babbling의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* babbling[], size_t babbling_len) {
	int answer = 0;

	int nBabblingIndex = 0;
	int nStringLen = 0;
	char* pivot = NULL;
	int nIsInvalid = 0;

	for (nBabblingIndex = 0; nBabblingIndex < babbling_len; ++nBabblingIndex)
	{
		nIsInvalid = 0;
		pivot = babbling[nBabblingIndex];
		nStringLen = strlen(pivot);
		while (*pivot != '\0')
		{
			switch (*pivot) {
			case 'a':
				if ((*(++pivot) != 'y')
					|| (*(++pivot) != 'a'))
				{
					nIsInvalid = 1;
				}
				break;
			case 'y':
				if ((*(++pivot) != 'e'))
				{
					nIsInvalid = 1;
				}
				break;
			case 'w':
				if ((*(++pivot) != 'o')
					|| (*(++pivot) != 'o'))
				{
					nIsInvalid = 1;
				}
				break;
			case 'm':
				if ((*(++pivot) != 'a'))
				{
					nIsInvalid = 1;
				}
				break;
			default:
				nIsInvalid = 1;
				break;
			}
			++pivot;
			if (nIsInvalid == 1)
			{
				break;
			}
		}
		if (nIsInvalid == 0) ++answer;
	}

	return answer;
}