#include <tcinit/tcinit.h>
#include <tc/tc_startup.h>
#include <tc/emh.h>
#include <sa/user.h>
#include <sa/group.h>
#include <sa/role.h>
#include <stdarg.h>
#include <iostream>
#include "helper.hpp"

int ITK_user_main(int argc, char* argv[])
{
	int status;

	char* user_id = NULL;		 //User ID
	char* user_passwd = NULL;    //User Password
	char* user_group = NULL;     //User Group

	ITK(ITK_initialize_text_services(0));
	ITK(ITK_set_journalling(TRUE));

	// Ask User ID
	user_id = ITK_ask_cli_argument("-u=");

	// Ask User Password
	user_passwd = ITK_ask_cli_argument("-p=");

	// Ask User Group
	user_group = ITK_ask_cli_argument("-g=");
	printf("\Trying auto login to Teamcenter...\n");

	status = ITK(ITK_auto_login());
	if (status != ITK_ok)
	{
		int				index = 0;
		int				n_ifails = 0;
		const int* severities = 0;
		const int* ifails = 0;
		const char** texts = NULL;

		EMH_ask_errors(&n_ifails, &severities, &ifails, &texts);
		printf("%3d error(s) with ITK_auto_login\n", n_ifails);
		for (index = 0; index < n_ifails; index++)
		{
			printf("\tError #%d, %s\n", ifails[index], texts[index]);
		}
		return status;
	}
	else
	{
		std::cout << "\nLogin Successful.\n";
		std::cout << "\nHi Teamcenter !!! from Microsoft Visual Studio Community\n";
	}

	//GO HERE!
	if (status == ITK_ok)
	{
		int n;
		char
			*group_name[SA_name_size_c + 1] = { "" },
			*my_user_name = NULL,
			*role_name[SA_name_size_c + 1] = { "" },
			user_name[SA_name_size_c + 1] = { "" };
		tag_t
			group = NULLTAG,
			role = NULLTAG,
			* members = NULL,
			user = NULLTAG;

		strcpy(user_name, "infodba");
		ITK(SA_find_user2(user_name, &user));
		ITK(SA_ask_user_login_group(user, &group));
		ITK(SA_ask_group_name2(group, group_name));
		printf("The Group: %s - That incldues: %s\n", group_name, user_name);
		ITK(SA_ask_user_default_role_in_group(user, group, &role));
		ITK(SA_ask_role_name2(role, role_name));
		printf("Default role: %s - User: %s\n", role_name, user_name);
		ITK(SA_find_groupmember_by_role(role, group, &n, &members));
		printf("Num of Users: %d - Includes int Group: %s  and Role: %s\n", n, group_name, role_name);
		MEM_free(members);

	}
	
	std::cout << "Logout";
	ITK_exit_module(TRUE);
	ITK_set_journalling(FALSE);

	return status;
}
