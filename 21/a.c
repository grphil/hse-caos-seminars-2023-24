#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

int main() {
	char* dir_name = "../20";
	DIR* d = opendir(dir_name);

	struct dirent* f;
	while ((f = readdir(d))) {
		printf("%s\n", f->d_name);

		char* path;
		asprintf(&path, "%s/%s", dir_name, f->d_name);

		struct stat st;
		lstat(path, &st);
		printf("%o\n", st.st_mode);
		free(path);
	}
	free(f);
}