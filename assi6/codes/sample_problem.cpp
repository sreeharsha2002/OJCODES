#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

FILE *in, *out;

/*
    Starting from here, make modifications to the global variable, talk and main function
    to make it suitable for according to your problem.
*/
int t, tests;
int limqueries;
int leftrange, rightrange, guessed;

int talk(int t){
	int nqueries = 0;
    // The buffer should be set according to the lenght of output exptected from the solution
	char line[256];
	int i, g;

	do {
		if(fgets(line, 255, stdin) == NULL){
            // stdin pipeline, the other end of which was linked to stdout of your solution code has been closed(just like we are closing stdout of this file),
            // which means that your code has completed its execution, inspite of some test cases remaining
            exit(1);
        }
		for(i = strlen(line) - 1; i >= 0 && line[i] == '\n'; i--){
            line[i] = 0;
        }

		if(strncmp(line, "MY ", 3) == 0){
			 // Your code asked the guess
			if(nqueries >= limqueries){
                // Uh oh! You have exceeded your query limit! Exiting now!
				fprintf(out, "test case %d: QUERY LIMIT EXCEEDED!\n", t);
                exit(1);
			}
			if(sscanf(&line[3], "%d", &g)!=1 || g > rightrange || g < leftrange){
                // Don't use \n in the sscanf, since we have removed it above
                // The query was not proper
    			fprintf(out, "test case %d: invalid MY query '%s' after %d queries\n", t, line, nqueries);
    			exit(1);
			}
            // Giving feedback to your code
			printf("%d\n", g == guessed); fflush(NULL);
			nqueries++;
		}
        else if(strncmp(line, "YOUR ", 5) == 0){
            // You have guessed the number, whether it is right or wrong will be compared later
			fprintf(out, "%s\n", line);
			fprintf(stderr, "test case %d: # queries = %d\n", t, nqueries); fflush(NULL);
			break;
		}
        else{
            // Something unknown outputed from your code, cannot parse it!
            // Why writing it to out instead of stderr? So that when we compare, it gives wrong answer
			fprintf(out, "test case %d: unknown command '%s' after %d queries\n", t, line, nqueries);
			exit(1);
		}
	}while(1);
	return nqueries;
}

int main(int argc, char **argv){
	int i;
	size_t nbuf;
	char buf[256];
	int maxqueries, queries;

    if(argc-1!=2){
    	fprintf(stderr, "error: invalid number of arguments: %d, while 2 expected\n", argc-1); fflush(NULL);
    	exit(1);
    }

	// Make stdin/stdout unbuffered, just to be sure
    // Inspite of making stdin/stdout unbuffered, it is useful to use fflush
    // to immediately/forcefully write any pending statements to the appropriate pipeline
	if(setvbuf(stdin, NULL, _IONBF, 0) != 0 || setvbuf(stdout, NULL, _IONBF, 0) != 0){
		fprintf(stderr,"error: cannot set unbuffered I/O\n"); fflush(NULL);
		exit(1);
	}
    // in file is the file from where the test case is to be read
	in  = fopen(argv[1], "r");
    // out file is the file where answers of your code are stored, for comparison later
	out = fopen(argv[2], "w");
	if(in == NULL || out == NULL){
		fprintf(stderr, "error: could not open input and/or output file\n"); fflush(NULL);
		exit(1);
	}
    // scanf takes input from stdin only;
    // in order to take input from somewhere else, use fscanf
	if(fscanf(in, "%d\n", &tests) != 1){
    	fprintf(stderr,"error: failed to read number of test cases\n"); fflush(NULL);
    	exit(1);
	}
    // printf writes output to stdout only;
    // if you run this code as it is, you will see the results on the terminal,
    // but if you provide the executable of this file to the runpipe executable, it modifies the IO pipeline,
    // and thus the output here will be redirected to your solution code;
    // That is how interaction happens on OJ
    // Don't forget to use fflush after every expected output, here as well as in your solution code
	printf("%d\n", tests); fflush(NULL);
	maxqueries = 0;
	queries = 0;
	for(t = 1; t <= tests; t++){
		if(fscanf(in, "%d %d\n", &leftrange, &rightrange)!=2){
            // Look at the output of the fscanf in order to make
            // Normally stderr is redirected to the terminal, but you can stop that by appending "2>/dev/null"(without quotes) at the end of your executable, or "2>temp"
            // If you execute this code on terminal without stopping the stderr to terminal, you will see the stderr outputs of this file on the terminal,
            // but don't worry, that is for the stderr pipeline, and that won't be given to your code; only output in the stdout pipeline of this code will be given to your solution code
            // for OJ interaction, the stderr of this file is redirected to a log file,
            // so that you can look at that and see what went wrong and where
			fprintf(stderr, "error: failed to read 'leftrange' and 'rightrange' in test case %d\n", t); fflush(NULL);
			exit(1);
		}
        printf("%d %d\n", leftrange, rightrange); fflush(NULL);
        // The problem is to guess the number between [leftrange, rightrange],
        // there are rightrange - leftrange + 1 number from which the correct number has to be guessed,
        // but given that the number is between this range only, you can use one guess less
        limqueries = rightrange - leftrange;
        if(fscanf(in, "%d\n", &guessed)!=1){
            fprintf(stderr, "error: failed to read 'guessed' in test case %d\n", t); fflush(NULL);
            exit(1);
        }
        // You should not print the guess, because that's what the question is :P
        // printf("%d\n", guessed); fflush(NULL);
        // After writing the essential information which your code will be waiting for, it will now interact with your code
		queries = talk(t);
		maxqueries = (queries > maxqueries ? queries : maxqueries);
	}
	fprintf(stderr, "### max queries = %d\n", maxqueries); fflush(NULL);
    // We're done, send EOF to runpipe and to your solution
	fclose(stdout);
	// Copy any additional data from your program
	while((nbuf = fread(buf,1,256,stdin))>0){
        if(fwrite(buf,1,nbuf,out)!=nbuf){
            fprintf(stderr, "error: failed to write additional program data\n"); fflush(NULL);
            exit(1);
        }
    }
    // You would need to terminate this code manually if you are executing from the command line, since this while loop will never end
    // But if you are using runpipe executable, it will turn off stdin and thus you will exit from this while loop
    // If everything went well, this statement will appear in the log file
	fprintf(stderr, "jury program exited successfully!\n"); fflush(NULL);
	return 0;
}
