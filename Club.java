public class Club {
    private int id;
    private String name;
    private Player[] players;
    // add your code here

	// you are not allowed to write any other constructor
    public Club() {
        this.players = new Player[11];
    }
    public int playerCount=0;

	public double getSalary() {
        double total = 0;
        for (int i = 0; i < playerCount; i++) {
            total += players[i].getSalary();
        }
        return total;
    }
    public void setId(int n){
        this.id=n;
    }
    public void setName(String a){
        this.name=a;
    }
    public void addPlayer(Player p){
        players[playerCount]=p;
        playerCount++;
    }
    public String getName(){
        return this.name;
    }
    public int getId(){
        return this.id;
    }

    public Player getMaxSalaryPlayer(){
	    double max=-1;
	    Player p=new Player(1,"a");
	    for(int i=0;i<playerCount;i++)
        {
            if(players[i].getSalary()>max)
            {
                max=players[i].getSalary();
            }
        }
        for(int i=0;i<playerCount;i++)
        {
            if(max==players[i].getSalary())
            {
                p=players[i];
            }
        }
        return p;
    }
	
	// add your code here
}