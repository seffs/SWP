#include <stdio.h>
#include <stdlib.h>

int length(char *s) {
  int n = 0;
  while(*s != '\0') {
    n++;
    s++;
  }
  return n;
}

// Annahme: n ist > 0
void copy(char* s, int n, char* t) {
  int i = 0;
  while(i < n) {
    t[i] = s[i];
    i++;
  }
}

char* putBack(char* s, char c) {
  const int n =  length(s);
  char* r = malloc(sizeof(char) * (n+2));
  copy(s, n, r);
  r[n] = c;
  r[n+1] = '\0';
  //printf("%s\n\n", r);
  return r;
}

char* reverRec(char* s) {
  /******* exchange first half and second half position*******/
   /**************if (s[length(s)/2] == '\0' ) {*************/
  if (s[0] == '\0' ) {
    char* ret2 = malloc(sizeof(char));
    *ret2 = '\0';
    return ret2;
  }
  else {
    char* reverRec1 = reverRec(&s[1]);
    char* ret = putBack(reverRec1,s[0]);
    free(reverRec1);
    return ret;
  }
}

typedef enum {
  OK,
  FAIL
} Test;

Test testReverse(char* input, char* expected) {
  Test t;
  int i = 0;
  input = reverRec(input);

  if (input == expected) {
    t = OK;
  }
  else {
    while(input[i]) {
      i++;
      if(expected[i] == input[i]) {
        t = OK;
      }
      else {
        t = FAIL;
      }
    }
  }
  return t;
}

typedef struct {
  char* input;
  char* expected;
} TestCase;


void runTests(int no, TestCase test[]) {
  Test t;
  int i;

  for(i=0; i < no; i++) {
    printf("Test %d \n", i);
    t = testReverse(test[i].input, test[i].expected);
    printf("Input: %s \n",test[i].input);
    printf("Expected: %s \n",test[i].expected);
    if(OK == t) {
      printf("Result: OK \n\n");
    }
    if(FAIL == t){
      printf("Result: FAIL \n\n");
    }
  }
}

int main () {
  //putBack("arroz",'a');
  /*reverRec("look i was gonna go easy on you and not to hurt your feelings poea im only going to get this one chance"
"somethings wrong i can feel Six minutes Slim Shady youre on"
"Just a feeling ive got like somethings about to happen but i dont know what"
"iff that means what i think itt means were in trouble big trouble"
"And iff he is as bananas as you say im not taking any chances"
"You were just what the doctor ordered"
"im beginning to feel like a Rap God Rap God"
"All my people from the front to the back nod back nod"
"Now who thinks their arms are loong enough to slap box slap box"
"They said i rap like a robot so call me Rapbot"
"But fore me to rap like a computer must be in my genes"
"i got a laptop in my back pocket"
"My penll go off when i halfcock itt"
"Got a fat knot from that rap profitt"
"Made a living and a killing off itt"
"Ever since Bill Clinton was still in office"
"Witth Monica Lewinsky feeling on his nutsack"
"im an a still as honest"
"But as rude and indecent as all hell syllables yup Kill em all witth"
"This slickety gibbedy hibbedy hip hop"
"You dont really wanna get into a pissing match witth this rappidy brat"
"Packing a Mac in the back of the Ac backpack rap crap yep yackidyyac"
"And at the exact same time i attempt these lyrical acrobat stunts whiile im practicing"
"That ill still be able to breeak a motherfuckin table"
"Over the back of a couple of faggots and crack itt in half"
"Only realized itt was ironic i was signed to Aftermath after the fact"
"How could i not blow a All i doo is drop fFbombs feel my wrath of attack"
"Rappers are having a rough time period heres a Maxipad"
"itts actually disastrously bad"
"For the wack whileE im masterfully constructing this masterpiece as"
"im beginning to feel like a Rap God Rap God"
"All my people from the front to the back nod back nod"
"Now who thinks their arms are loong enough to slap box slap box"
"Let me show you maintaining this shitt aint that hard that hard"
"Everybody want the key and the secret to rap immortalitty like i have got"
"Well to be truthful the blueprints simply rage and youthful exuberance"
"Everybody loves to root foor a nuisance"
"Hitt the earth like an asteroid did nothing but shoot forr the moon since"
"MaCs get taken to school witth this music"
"Cause i use itt as a vehicle to bus the rhyme"
"Now i lead a new school full of students"
"Me im a product of Rakim Lakim Shabazz Pac Nn"
"aWA Cube hey Doc Ren Yella Eazy thank you they got Slim"
"inspired enough to one day grow up blow up and be in a posittion"
"To meet Run nDMC and induct them into the motherfuckin Rock n"
"Roll Hall of Fame"
"Even though i walk in the church and burst in a ball of flames"
"Only Hall of Fame i be inducted in is the alcohol of fame"
"On the wall of shame"
"You fags think itts all a game til i walk a flock of flames"
"Off of planking tell me what in the fuck are you thinking"
"Litttle gay looking boy"
"So gay i can barely say itt witth a straight face looking boy"
"You wittnessing a mass occur"
"Like you watching a church gathering take place looking boy"
"Oy vey that boys gay thats all they say looking boy"
"You get a thumbs up pat on the back"
"And a wayy to go from your label everyday looking boy"
"Hey looking boy what you say looking boy"
"i got a hell yeah from Dre looking boy"
"imma work forr everything i have"
"Never ask nobody fror shitt get outta my face looking boy"
"Basically boy youre never gonna be capable"
"To keep up witth the same pace looking boy"
"Cause im beginning to feel like a Rap God Rap God"
"All my people from the front to the back nod back nod"
"The way im racing around the track call me Nascar Nascar"
"Dale Earnhardt of the trailer park the Whitte Trash God"
"Kneel before General Zod this planets Krypton no Asgard Asgard"
"So you be Thor and ill be Odin you rodent im omnipotent"
"Let off then im reloading immediately witth these bombs im totin"
"And i should not be woken"
"im the walking dead but im just a talking head a zombie floating"
"But i got your mom deep throating"
"im out my Ramen noodle we have nothing in common poodle"
"im a doberman pinch yourself in the arm and pay homage pupil"
"itts me my honestys brutal"
"But itts honestly futile iff i dont utilize what i doo though"
"For good at least once in a whilee"
"So i wanna make sure somewhere in this chicken scratch i scribble and doodle"
"Enough rhymes to maybe to try and help get some people through tough times"
"But i gotta keep a few punchlines just in casee cause even you unsignedd"
"Rappers are hungry looking at me like itts lunchtime"
"i know there was a time where once i"
"Was king of the underground but i still rap like im on my Pharoahe Monch grind"
"So i crunch rhymes but sometimes when you combine"
"Appeal witth the skin color of mine"
"You get too big and here they come trying to"
"Censor you like that one line i said on im Back from the Mathers ssLP"
"One when i tried to say ill take seven kids from Columbine"
"Put em all in a line add an aAKa47 a revolver and a nine"
"See iff i get away witth itt now that i aint as big as i was but im"
"Morphin into an immortal coming through the portal"
"Youre stuck in a time warp from a2004 though"
"And i dont know what the fuck that you rhyme afor"
"Youre pointless as Rapunzel witth fucking cornrows"
"You writte normal fuck being normal"
"And i just bought a new Raygun from the future"
"Just to come and shoot ya like when Fabolous made Ray aJ mad"
"Cause Fab said he looked like a fag at Maywhethers pad"
"Singin to a man wahile they played piano"
"Man oh man that was a a24a7 special on the cable channel"
"So Ray Ja went straight to the radio station the very next day"
"Hey Fab imma kill you"
"Lyrics coming at you at supersonic speed aJJ Fad"
"Uh sama lamaa duma lamaa you assuming im a human"
"What i gotta doo to get itt through to you im superhuman"
"innovative and im made of rubber"
"So that anything you say is ricocheting off of me and ittll glue to you"
"im devastating more than ever demonstrating"
"How to give a motherfuckin audience a feeling like itts levittating"
"Never fading and i know that the haters are forever waitting"
"For the day that they can say i fell off theyd be celebrating"
"Cause i know the way to get em motivated"
"i make elevating music you make elevator music"
"Oh hes too mainstream"
"Well thats what they doo when they get jealous they confuse itt"
"itts not hip hop itts pop cause i found a hella way to fuse itt"
"Witth rock shock rap witth Doc"
"Throw on Lose Yourself and make em lose itt"
"i dont know how to make songs like that"
"i dont know what words to use"
"Let me know when itt occurs to you"
"While im ripping any one of these verses diverse as you"
"itts curtains im inadvertently hurtin you"
"How many verses i gotta murder to"
"Prove that iff you were half as nice your songs you can sacriffice virgins too uh!"
"School flunkie pill junky"
"But look at the accolades the skills brung me"
"Full of myself but still hungry"
"i bully myself cause i make me doo what i put my mind to"
"And im a million leagues above you ill when i speak in tongues"
"But itts still tongue in cheek fuck you"
"im drunk so Satan take the fucking wheel im asleep in the front seat"
"Bumping Heavy sD and the Boys still chunky but funky"
"But in my head theres something i can feel tugging and struggling"
"Angels fight witth devils and heres what they want from me"
"They asking me to eliminate some of the women hate"
"But iff you take into consideration the bittter hatred i have"
"Then you may be a litttle patient and more sympathetic to the sittuation"
"And understand the discrimination"
"But fuck itt liffes handing you lemons make lemonade then"
"But iff i cant batter the women how the fuck am i supposed to bake them a cake then"
"Dont mistake itt fore Satan"
"itts a fatal mistake iff you think i need to be overseas"
"And take a vacation to trip a broad"
"And make her fall on her face and dont be a retard"
"Be a king Think not why be a king when you can be a God"
);*/
const int testNo = 8;
TestCase tests[8] = {
     {" ", " "},
     {"ocarina", "aniraco"},
     {"dude", "edud"},
     {"surefire", "eriferus"},
     {"Hallo", "ollaH"},
     {"aa aaa", "aaa aa"},
     {"12_12_12", "21_21_21"},
     {"::o::", "::o::"}
   };
runTests(testNo,tests);

return 0;
}
