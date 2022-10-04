#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct baseball
{
    char t_name[20];
    int no_of_win;
    int no_of_matches;
    int no_of_loss;
    int no_of_hit;
    int no_of_run;
    int no_of_error;
    int no_of_extra_innings;
}baseball;
typedef struct football
{
    char t_name[20];
    int no_of_win;
    int no_of_matches;
    int no_of_loss;
    int no_of_ties;
    int no_of_touchdowns;
    int no_of_fieldgoals;
    int no_of_turnovers;
    int no_of_yards_gained;
    int no_of_yards_loss;
}football;

void details(int i,baseball teams[])
{
    printf("Details of Baseball Team-%d :",i+1);
    printf("\n\tEnter the team name :");
    scanf("%s",teams[i].t_name);
    printf("\n\tEnter the number of wins :");
    scanf("%d",&teams[i].no_of_win);
    printf("\n\tEnter the number of Matches played :");
    scanf("%d",&teams[i].no_of_matches);
    printf("\n\tEnter the number of loss :");
    scanf("%d",&teams[i].no_of_loss);
    printf("\n\tEnter the number of hits :");
    scanf("%d",&teams[i].no_of_hit);
    printf("\n\tEnter the number of runs :");
    scanf("%d",&teams[i].no_of_run);
    printf("\n\tEnter the number of errors :");
    scanf("%d",&teams[i].no_of_error);
    printf("\n\tEnter the number of extra innings :");
    scanf("%d",&teams[i].no_of_extra_innings);
}

void details_football(int i,football team[])
{
    printf("Details of Football Team-%d :",i+1);
    printf("\n\tEnter the team name :");
    scanf("%s",team[i].t_name);
    printf("\n\tEnter the number of wins :");
    scanf("%d",&team[i].no_of_win);
    printf("\n\tEnter the number of matches played :");
    scanf("%d",&team[i].no_of_matches);
    printf("\n\tEnter the number of loss :");
    scanf("%d",&team[i].no_of_loss);
    printf("\n\tEnter the number of ties :");
    scanf("%d",&team[i].no_of_ties);
    printf("\n\tEnter the number of touchdowns :");
    scanf("%d",&team[i].no_of_touchdowns);
    printf("\n\tEnter the number of field goals :");
    scanf("%d",&team[i].no_of_fieldgoals);
    printf("\n\tEnter the number of turn overs :");
    scanf("%d",&team[i].no_of_turnovers);
    printf("\n\tEnter the total number of yards gained :");
    scanf("%d",&team[i].no_of_yards_gained);
    printf("\n\tEnter the total number of yards given to opponents :");
    scanf("%d",&team[i].no_of_yards_loss);
    printf("\n");
}

void print_base(int i,baseball teams[])
{
    printf("\nTeam name :%s",teams[i].t_name);
    printf("\nNumber of Wins :%d",teams[i].no_of_win);
    printf("\nNumber of Matches played :%d",teams[i].no_of_matches);
    printf("\nNumber of Loss :%d",teams[i].no_of_loss);
    printf("\nNumber of Hits :%d",teams[i].no_of_hit);
    printf("\nNumber of Runs :%d",teams[i].no_of_run);
    printf("\nNumber of Errors :%d",teams[i].no_of_error);
    printf("\nNumber of Extra Innings :%d",teams[i].no_of_extra_innings);
}

void print_foot(int i,football team[])
{
    printf("\nTeam name :%s",team[i].t_name);
    printf("\nNumber of Wins :%d",team[i].no_of_win);
    printf("\nNumber of Matches played :%d",team[i].no_of_matches);
    printf("\nNumber of Loss :%d",team[i].no_of_loss);
    printf("\nNumber of Ties :%d",team[i].no_of_ties);
    printf("\nNumber of Touch Down :%d",team[i].no_of_touchdowns);
    printf("\nNumber of Field Goals :%d",team[i].no_of_fieldgoals);
    printf("\nNumber of Turn Overs :%d",team[i].no_of_turnovers);
    printf("\nNumber of Yards gained :%d",team[i].no_of_yards_gained);
    printf("\nNumber of Yards given to opponents :%d",team[i].no_of_yards_loss);
}

int main()
{
    int i,num,backup,option,index,value,score_max=0,order=0,m=0,opt;
    printf("Choose the sport(Basketball-1/Football-2):");
    scanf("%d",&option);
    printf("Enter the total number of teams :");
    scanf("%d",&num);
    if(option==1)
    {
        baseball teams[num];
        int base_win[num][2];
        for(i=0;i<num;i++)
        {
            base_win[i][1]=0;
        }
        for(i=0;i<num;i++)
        {
            details(i,teams);
        }
        printf("\n\t\t------------Baseball Results-------------");
        for(m=0;m<num;m++)
        {
            for(i=0;i<num;i++)
            {
                if(teams[i].no_of_win>score_max)
                {
                    score_max=teams[i].no_of_win;
                    base_win[order][1]=score_max;
                    backup=i;
                }
            }
            base_win[m][0]=backup;
            teams[backup].no_of_win=0;
            score_max=0;
            order++;
        }

        FILE *fptr;
    	fptr=fopen("Baseballteam.txt","wb");
    	if(fptr==NULL)
    	{
    		printf("File doesn't Exists");
    	}
    	else
    	{
    	    fwrite(teams,sizeof(struct baseball),num,fptr);
    	}
    	fptr=fopen("Baseballteam.txt","rb");
    	if(fptr==NULL)
    	{
    		printf("File doesn't exists");
    	}
    	else
    	{
    		fread(teams,sizeof(struct baseball),num,fptr);

        	for(i=0;i<num;i++)
                {
                    index=base_win[i][0];
                    value=base_win[i][1];
                    teams[index].no_of_win=value;
                    print_base(index,teams);
                    printf("\n\n");
                }
    	}
    	fclose(fptr);

    	int win_rate[num],win_rate_max=0,subscript,loss=25000,loss_index,run_max=0,run_index,win=0,win_index,say;
    	do
        {
            printf("Enter 1-to view maximum win rate\n2-to view maximum wins\n3-to view minimum loss\n4-to view maximum runs\n");
            scanf("%d",&opt);
            switch (opt)
            {
            case 1 :
            {
                for(i=0;i<num;i++)
                {
                    win_rate[i]=teams[i].no_of_win/teams[i].no_of_matches;
                }
                for(i=0;i<num;i++)
                {
                    if(win_rate[i]>win_rate_max)
                    {
                        win_rate_max=win_rate[i];
                        subscript=i;
                    }
                }
                printf("The Team with highest win rate is %s with win rate of %d\n",teams[subscript].t_name,win_rate_max);
                break;
            }
            case 2 :
            {
                for(i=0;i<num;i++)
                {
                    if(teams[i].no_of_win>win)
                    {
                        win=teams[i].no_of_win;
                        win_index=i;
                    }
                }
                printf("The team %s has maximum wins of %d\n",teams[win_index].t_name,win);
                break;
            }
            case 3 :
            {
                for(i=0;i<num;i++)
                {
                    if(teams[i].no_of_loss<loss)
                    {
                        loss=teams[i].no_of_loss;
                        loss_index=i;
                    }
                }
                printf("The Team with least loss count is %s with loss count of %d\n",teams[loss_index].t_name,loss);
                break;
            }

            case 4 :
            {
                for(i=0;i<num;i++)
                {
                    if(teams[i].no_of_run>run_max)
                    {
                        run_max=teams[i].no_of_run;
                        run_index=i;
                    }
                }
                printf("The Team with highest run count is %s with run count of %d\n",teams[run_index].t_name,run_max);
                break;
                }
            }
            printf("Do you wish to continue(YES=1/NO=2):");
            scanf("%d",&say);
        }while(say!=2);
    }
    else
    {
        int foot_win[num][2];
        football team[num];
        for(i=0;i<num;i++)
        {
            foot_win[i][1]=0;
        }
        for(i=0;i<num;i++)
        {
            details_football(i,team);
        }
        printf("\n\t\t------------Football Results-------------");
        for(m=0;m<num;m++)
        {
            for(i=0;i<num;i++)
            {
                if(team[i].no_of_win>score_max)
                {
                    score_max=team[i].no_of_win;
                    foot_win[order][1]=score_max;
                    backup=i;
                }
            }
            foot_win[m][0]=backup;
            team[backup].no_of_win=0;
            score_max=0;
            order++;
        }
        FILE *fptr;
    	fptr=fopen("Footballteam.txt","wb");
    	if(fptr==NULL)
    	{
    		printf("File doesn't Exists");
    	}
    	else
    	{
    	    fwrite(team,sizeof(struct football),num,fptr);
    	}
    	fptr=fopen("Footballteam.txt","rb");
    	if(fptr==NULL)
    	{
    		printf("File doesn't exists");
    	}
    	else
    	{
    		fread(team,sizeof(struct football),num,fptr);
        	for(i=0;i<num;i++)
                {
                    index=foot_win[i][0];
                    value=foot_win[i][1];
                    team[index].no_of_win=value;
                    print_foot(index,team);
                    printf("\n\n");
                }
    	}
    	fclose(fptr);
        int win_rate[num],win_rate_max=0,subscript,loss=25000,loss_index,goal_max=0,goal_index,win=0,win_index,say;
    	do
        {
            printf("Enter 1-to view maximum win rate\n2-to view maximum wins\n3-to view minimum loss\n4-to view maximum runs\n");
            scanf("%d",&opt);
            switch (opt)
            {
            case 1 :
            {
                for(i=0;i<num;i++)
                {
                    win_rate[i]=team[i].no_of_win/team[i].no_of_matches;
                }
                for(i=0;i<num;i++)
                {
                    if(win_rate[i]>win_rate_max)
                    {
                        win_rate_max=win_rate[i];
                        subscript=i;
                    }
                }
                printf("The Team with highest win rate is %s with win rate of %d\n",team[subscript].t_name,win_rate_max);
                break;
            }
            case 2 :
            {
                for(i=0;i<num;i++)
                {
                    if(team[i].no_of_win>win)
                    {
                        win=team[i].no_of_win;
                        win_index=i;
                    }
                }
                printf("The team %s has maximum wins of %d\n",team[win_index].t_name,win);
                break;
            }
            case 3 :
            {
                for(i=0;i<num;i++)
                {
                    if(team[i].no_of_loss<loss)
                    {
                        loss=team[i].no_of_loss;
                        loss_index=i;
                    }
                }
                printf("The Team with least loss count is %s with loss count of %d\n",team[loss_index].t_name,loss);
                break;
            }

            case 4 :
            {
                for(i=0;i<num;i++)
                {
                    if(team[i].no_of_fieldgoals>goal_max)
                    {
                        goal_max=team[i].no_of_fieldgoals;
                        goal_index=i;
                    }
                }
                printf("The Team with highest goal count is %s with goal count of %d\n",team[goal_index].t_name,goal_max);
                break;
                }
            }
            printf("Do you wish to continue(YES=1/NO=2):");
            scanf("%d",&say);
        }while(say!=2);
    }
}
