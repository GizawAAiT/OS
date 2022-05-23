
#include <stdio.h>
#include <stdlib.h>
//create enumerator state to hold the state of context.

enum States {
  NORMAL,
  SLASH,
  INCOMMENT,
  TO_CLOSE_COMMENT,
  INSTRING,
  INCHARS,
  CHAR_ESCAPE,
  STRING_ESCAPE,
  SINGLE_COTE_ESCAPE,
  IN_COMMENT_ESCAPE,
} States;

/* this handler function takes a normal condition and determine 
the next state bsed on the current character input*/

void normalState(int character, enum States *state) {
  
  if (character == '/') {
    *state = SLASH;
 
  } else if (character == '"') {
    *state = INSTRING;
    putchar(character);
 
  } else if (character == '\'') {
    *state = INCHARS;
    putchar(character);
 
  } else if (character == '\\') {
    *state = CHAR_ESCAPE;
  
  } else {
    *state = NORMAL;
    putchar(character);
  }
}

/*what if the state is  immediatly after a slash comes.
i.e. if '*' comes, the comment starts succesfully.*/

void preComment(int character, enum States *state) {

  if (character == '*') {
    *state = INCOMMENT;
    putchar(' ');
  }
/*keep waiting if / comes repetedly and the / except 
just behind '*' is considered as part of commented code*/
  
  else if (character == '/') {
    *state = SLASH;
     putchar(character);
  }

  else {
    *state = NORMAL;
    putchar('/');
    putchar(character);
  }
}

/* After the comment started by slash and comma,
if the star emmerged, then it will attempt to decomment 
the file in between the slashStar and StarSlash and */

void inComment(int character, enum States *state) {
 
  if (character == '*') {
    *state = TO_CLOSE_COMMENT;
 
  } else if (character == '\\') {
    *state = IN_COMMENT_ESCAPE;
 
  } else {
    *state = INCOMMENT;
  }
}

/* this function takes the state when only a slash 
requered to decomment the previous characters.
so, if it gets / , the commente will be removed otherwise
it is inside yhte comment still.  */

void toCloseComment(int character, enum States *state) {
 
  if (character == '/') {
    *state = NORMAL;
 
  } else if (character == '*') {
    *state = TO_CLOSE_COMMENT;
  
  } else {
    *state = INCOMMENT;
  }
}

/*the state is after double cotation emerged.
so, it will wait until it gets the same double cotation.*/
void inString(int character, enum States *state) {
 
  if (character == '"') {
    *state = NORMAL;
    putchar(character);
 
  } else if (character == '\\') {
    *state = STRING_ESCAPE;
 
  } else {
    *state = INSTRING;
    putchar(character);
  }
}

/*the state is after single cotation emerged
so, it will wait until it gets the same single 
cotation to close the character .............*/

void inChars(int character, enum States *state) {
 
  if (character == '\'') {
    *state = NORMAL;
    putchar(character);
 
  } else if (character == '\\') {
    *state = SINGLE_COTE_ESCAPE;

  } else {
    *state = INCHARS;
    putchar(character);
  }
}

/* After the escape backslash comes inside a single cotted character,
 this function will be called and if letter(n) comes, that means it's
 new line. the state is still normal................................. */
void charEscapeState(int character, enum States *state, int *line) {
 
  if (character == 'n') {
    putchar(' ');
    (*line)++;
 
  } else {
    putchar('\\');
    putchar(character);
 
  }
  *state = NORMAL;
}

/* After the escape backslash comes inside a double cotted character,
 this function will be called and if letter(n) comes, that means it's
 new line. the state is still string................................ */
void stringEscapeState(int character, enum States *state, int *line) {
 
  if (character == 'n') {
    putchar('n');
    (*line)++;
 
  } else {
    putchar('\\');
    putchar(character);
  
  }
  *state = INSTRING;
}


/*if we get a backslsh(escape character) inside single cotted 
character...................................................*/
void charsEscapeState(int character, enum States *state, int *line) {
  
  if (character == 'n') {
    putchar('n');
    (*line)++;

  } else {
    putchar('\\');
    putchar(character);
  }

  *state = INCHARS;
}
/*if we get a backslsh(escape character) inside single cotted 
character...................................................*/
void commentEscapeState(int character, enum States *state, int *line) {

  if (character == 'n') {
    putchar('n');
    (*line)++;

  } else {
    putchar('\\');
    putchar(character);
  }

  *state = INCOMMENT;
}

/*this function relates state and state handler methods everytime called in the while 
loop for each charcter in the file.
It also increament the line number every time the new line emerges.*/

int stateFunctionMapper(int character, enum States *state, int *line) {

  if (character == '\n') {
    (*line)++;
  }

  switch (*state)
  {

  case NORMAL:
    normalState(character, state);
    break;

  case SLASH:
     preComment(character, state);
    break;

  case INCOMMENT:
    inComment(character, state);
    break;

  case TO_CLOSE_COMMENT:
    toCloseComment(character, state);
    break;

  case INSTRING:
    inString(character, state);
    break;

  case INCHARS:
    inChars(character, state);
    break;

  case CHAR_ESCAPE:
    charEscapeState(character, state, line);
    break;

  case STRING_ESCAPE:
    stringEscapeState(character, state, line);
    break;

  case SINGLE_COTE_ESCAPE:
    charsEscapeState(character, state, line);
    break;

  case IN_COMMENT_ESCAPE:
    commentEscapeState(character, state, line);
    break;

  default:
    break;
  } 
}


/*start the while loop inside a mail function for the entire
text in the file......................................*/

int main(int argc, char *argv[]) {
 
  FILE *file;
  enum States state;
  state = NORMAL;
  int line = 0;
  int character;
  if (argc == 1) {
   
    while ((character = getchar()) != EOF) {
      stateFunctionMapper(character, &state, &line);
    }
  }

  if (state == INCOMMENT || state == TO_CLOSE_COMMENT) {
    fprintf(stderr, "Error: line %d: unterminated comment\n", line);
    exit(-1);
  }
 
  return 0;
}
