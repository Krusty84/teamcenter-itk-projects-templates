#pragma once
//wrapper for calling ITK function
#define ITK(X) 							\
		printf(#X);								\
		fflush(NULL);							\
		status=X; 								\
		if (status != ITK_ok ) 					\
		{										\
			int				index = 0;			\
			int				nIfails = 0;		\
			const int*		severities = 0;		\
			const int*		ifails = 0;			\
			const char**	texts = NULL;		\
												\
			EMH_ask_errors( &nIfails, &severities, &ifails, &texts);				\
			printf("\t%3d error(s)\n", nIfails);									\
			for( index=0; index<nIfails; index++)									\
			{																		\
				printf("\tError #%d, %s\n", ifails[index], texts[index]);			\
			}																		\
			return status;															\
		}																		\
		else									\
		{										\
			printf("\tSUCCESS\n");				\
		}