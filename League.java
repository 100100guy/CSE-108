public class League {
    private Match[] matches;
    private int matchCount;
    private int clubCount;
    private Club[] clubs;
    private String name;
    // add your variables here, if required

    public League() {
        // assume a league can have at most 5 clubs, add code for initialization accordingly
        clubCount = 0;
        matchCount = 0;
        clubs = new Club[5];
    }
    // add your methods here, if required

    public void setName(String name) {
        this.name = name;
    }

    public void addClub(Club c) {
        Club temp=new Club();
        temp=c;
        clubs[clubCount] = temp;
        clubCount++;

    }

    public void removeClub(Club c) {
        for (int i = 0; i < clubCount; i++) {
            if (clubs[i] == c) {
                for (int j = i + 1; j < clubCount; j++) {
                    clubs[j - 1] = clubs[j];
                }
                break;
            }
        }
        clubCount--;
    }


    public void printLeagueInfo() {
        System.out.println("League : " + name);
        printClubs();
    }

    public void printClubs() {
        System.out.println("Clubs:");
        // print the name of the clubs of this league, each one on a line
        for (int i = 0; i < clubCount; i++) {
            System.out.println(clubs[i].getName());
        }
    }


        public void scheduleMatches () {
            matchCount = (clubCount * (clubCount - 1));
            matches = new Match[matchCount];
            int matchNo = 0;
            for (int i = 0; i < clubCount; i++) {
                for (int j = 0; j < clubCount; j++) {
                    // check the constructor of the Match class and add your code here
                    if (i != j) {

                        matches[matchNo] = new Match(matchNo, clubs[i], clubs[j]);
                        matchNo++;
                        // note that there will be two matches between club A and club B
                        // in the first match, club A will play as the home team and in the second match, as the away team
                    }
                }
            }
        }

        public void simulateMatches () {
            for (int i = 0; i < matchCount; i++) {
                matches[i].play();
            }
        }
        public void printMatches () {
            System.out.println("Matches: ");
            for (int i = 0; i < matchCount; i++) {
                matches[i].showResult();
            }
        }

        public void showStandings () {
            // sort the clubs in descending order of points
            // note that, the sequence in which clubs were added to the league, should be unchanged
            // check the given sample output for clarification
            // (carefully observe the output of showStandings() followed by printLeagueInfo() method calls
            // you can use additional arrays if needed
            // print the clubs in descending order of points
            int points[]=new int[clubCount];
            int standings[]=new int[clubCount];
            for (int i = 0; i < clubCount; i++) {
                points[i] = 0;
            }

            for (int i = 0; i < matchCount; i++) {
                for (int j = 0; j < clubCount; j++) {
                    if(matches[i].ishometeamwon==2 && matches[i].getHomeTeam()==clubs[j])
                    {
                        points[j]+=1;
                    }
                    if(matches[i].ishometeamwon==1 && matches[i].getHomeTeam()==clubs[j])
                    {
                        points[j]+=2;
                    }
                    if(matches[i].ishometeamwon==0 && matches[i].getHomeTeam()==clubs[j])
                    {
                        points[j]+=0;
                    }
                }
            }
            for (int i = 0; i < matchCount; i++) {
                for (int j = 0; j < clubCount; j++) {
                    if(matches[i].isawayteamwon==2 && matches[i].getAwayTeam()==clubs[j])
                    {
                        points[j]+=1;
                    }
                    if(matches[i].isawayteamwon==1 && matches[i].getAwayTeam()==clubs[j])
                    {
                        points[j]+=2;
                    }
                    if(matches[i].isawayteamwon==0 && matches[i].getAwayTeam()==clubs[j])
                    {
                        points[j]+=0;
                    }

                }
            }
            for (int i = 0; i < clubCount; i++) {
                standings[i] = points[i];
            }
            int tmp;
                for (int i = 0; i <  clubCount - 1 ; i++) {
                    for (int j = 0; j < clubCount - i - 1; j++) {
                        if (standings[j] < standings[j+1])
                        {
                            tmp = standings[j];
                            standings[j] = standings[j+1];
                            standings[j+1] = tmp;
                        }
                    }
                }
                int start=1;
                int alreadydisplayed[]=new int[clubCount];
                for (int i=0;i<clubCount;i++){
                    alreadydisplayed[i]=0;
                }

                System.out.println("Sl. - Club - Points");
                for (int i = 0; i < clubCount; i++) {
                    for (int j = 0; j < clubCount; j++)
                        if(standings[i]==points[j] && alreadydisplayed[j]==0 ) {
                            System.out.println(start + ".     " + clubs[j].getName() + "     " + points[j]);
                            standings[i]=-1;
                            alreadydisplayed[j]=1;
                            start++;
                        }
                }

            }

        }




