//  Student Name: Rishi Vimalendran
//  Student Number:  20826980
//
//  SYDE 121 Assignment: 03
//  Filename: lab03_01
//
// I hereby declare that this code, submitted for credit for the course//  SYDE121, is a product of my own efforts.  This coded solution has//  not been plagiarized from other sources and has not been knowingly//  plagiarized by others.
//
// Project : Soccer Simulation
// Purpose : To simulate a game of soccer with various events and commentary for those events, while outputting stats at halftime and fulltime
/*
 I ran the program multiple times and then manually checked that the stats were consistent with the outputted commentary
 The stats were outputting unrealistic numbers (e.g. a negative number) which were caused by not initializing every stat variable, which was then fixed
 */

#include <iostream>

using namespace std;
// generates a number from [1. 30] for the number of events in the game
int generate_number_of_events ();

// outputs commentary for different instances of the shot event adds to the stat variables depending on which instance has occurred
void shot_event (int event_1, int sub_event, int& team_a_goals, int& team_b_goals, int& team_a_shots_on_goal, int& team_b_shots_on_goal, int& team_a_missed_shots, int& team_b_missed_shots, int& team_a_blocked_shots, int& team_b_blocked_shots);


// outputs commentary for different instances of the free kick event adds to the stat variables depending on which instance has occurred
void free_kick_event_team_a (int sub_event, int foul_event, int& team_a_goals, int& team_a_shots_on_goal, int& team_a_missed_shots, int& team_b_blocked_shots, int& team_b_fouls, int& team_b_yellow_cards, int& team_b_red_cards);


void free_kick_event_team_b (int sub_event, int foul_event, int& team_b_goals, int& team_b_shots_on_goal, int& team_b_missed_shots, int& team_a_blocked_shots, int& team_a_fouls, int& team_a_yellow_cards, int& team_a_red_cards);

// outputs commentary for different instances of the penalty event adds to the stat variables depending on which instance has occurred
void penalty_event_team_a (int sub_event, int foul_event, int& team_a_goals, int& team_a_shots_on_goal, int& team_a_missed_shots, int& team_b_fouls, int& team_b_yellow_cards, int& team_b_red_cards);


void penalty_event_team_b (int sub_event, int foul_event, int& team_b_goals, int& team_b_shots_on_goal, int& team_b_missed_shots, int& team_a_fouls, int& team_a_yellow_cards, int& team_a_red_cards);


void sub_event_level_2 (int events, int event_1, int& team_a_goals, int& team_b_goals, int& team_a_shots_on_goal, int& team_b_shots_on_goal, int& team_a_missed_shots, int& team_b_missed_shots, int& team_a_blocked_shots, int& team_b_blocked_shots, int& team_a_fouls, int& team_b_fouls, int& team_a_yellow_cards, int& team_b_yellow_cards, int& team_a_red_cards, int& team_b_red_cards);

// outputs half-time stats
void stats_output_half (int team_a_goals, int team_b_goals, int team_a_shots_on_goal, int team_b_shots_on_goal, int team_a_missed_shots, int team_b_missed_shots, int team_a_blocked_shots, int team_b_blocked_shots, int team_a_fouls, int team_b_fouls, int team_a_yellow_cards, int team_b_yellow_cards, int team_a_red_cards, int team_b_red_cards);

// outputs full-time stats
void stats_output_full (int team_a_goals, int team_b_goals, int team_a_shots_on_goal, int team_b_shots_on_goal, int team_a_missed_shots, int team_b_missed_shots, int team_a_blocked_shots, int team_b_blocked_shots, int team_a_fouls, int team_b_fouls, int team_a_yellow_cards, int team_b_yellow_cards, int team_a_red_cards, int team_b_red_cards);


void start_game (int events);


int main()
{
    //creates randomness
    srand (time(NULL));
    //executes game simulation
    start_game(generate_number_of_events());
}

int generate_number_of_events ()
{
    int number_of_events = rand() % 30 + 1;
    
    cout << "Number of Events: " << number_of_events << "\n";
    return number_of_events;
}

void start_game (int events)
{
    // initializes all stat variables
    int team_a_goals = 0, team_b_goals = 0, team_a_shots_on_goal = 0, team_b_shots_on_goal = 0;
    int team_a_missed_shots = 0, team_b_missed_shots = 0, team_a_blocked_shots = 0, team_b_blocked_shots = 0;
    int team_a_fouls = 0, team_b_fouls = 0, team_a_yellow_cards = 0, team_b_yellow_cards = 0;
    int team_a_red_cards = 0, team_b_red_cards = 0;
    
    int sub_event_1;
    //  randomly creates a number of specific events according to the random number of events generated
    for (int i = 1; i <= events; i++)
    {
        sub_event_1 = rand() % 6 + 1;
        // calls a function that will further specify the event occurring
        sub_event_level_2(events, sub_event_1, team_a_goals, team_b_goals, team_a_shots_on_goal, team_b_shots_on_goal, team_a_missed_shots, team_b_missed_shots, team_a_blocked_shots, team_b_blocked_shots, team_a_fouls, team_b_fouls, team_a_yellow_cards, team_b_yellow_cards, team_a_red_cards, team_b_red_cards);
        // if ~half of the events have occurred the half-time function is called
        if (i == (events/2))
        {
            stats_output_half(team_a_goals, team_b_goals, team_a_shots_on_goal, team_b_shots_on_goal, team_a_missed_shots, team_b_missed_shots, team_a_blocked_shots, team_b_blocked_shots, team_a_fouls, team_b_fouls, team_a_yellow_cards, team_b_yellow_cards, team_a_red_cards, team_b_red_cards);
        }
        // if all of the events have occurred the full-time function is called
        if (i == events)
        {
            stats_output_full(team_a_goals, team_b_goals, team_a_shots_on_goal, team_b_shots_on_goal, team_a_missed_shots, team_b_missed_shots, team_a_blocked_shots, team_b_blocked_shots, team_a_fouls, team_b_fouls, team_a_yellow_cards, team_b_yellow_cards, team_a_red_cards, team_b_red_cards);
        }
    }
}

void sub_event_level_2 (int events, int event_1, int& team_a_goals, int& team_b_goals, int& team_a_shots_on_goal, int& team_b_shots_on_goal, int& team_a_missed_shots, int& team_b_missed_shots, int& team_a_blocked_shots, int& team_b_blocked_shots, int& team_a_fouls, int& team_b_fouls, int& team_a_yellow_cards, int& team_b_yellow_cards, int& team_a_red_cards, int& team_b_red_cards)
{
    int sub_event;
    int foul_event;
    // generates a random subevent (and foul event if necessary) for the event and calls the specific event function
    switch (event_1)
    {
        case 1:
            
        case 2: sub_event = rand() % 4;
            shot_event(event_1, sub_event, team_a_goals, team_b_goals, team_a_shots_on_goal, team_b_shots_on_goal, team_a_missed_shots, team_b_missed_shots, team_a_blocked_shots, team_b_blocked_shots);
            break;
            
        case 3:sub_event = rand() % 4;
            foul_event = rand () % 3;
            free_kick_event_team_a(sub_event, foul_event, team_a_goals, team_a_shots_on_goal, team_a_missed_shots, team_b_blocked_shots, team_b_fouls, team_b_yellow_cards, team_b_red_cards);
            break;
            
        case 4: sub_event = rand() % 4;
            foul_event = rand () % 3;
            free_kick_event_team_b(sub_event, foul_event, team_b_goals, team_b_shots_on_goal, team_b_missed_shots, team_a_blocked_shots, team_a_fouls, team_a_yellow_cards, team_a_red_cards);
            break;
            
        case 5: sub_event = rand() % 3;
            foul_event = rand () % 3;
            penalty_event_team_a(sub_event, foul_event, team_a_goals, team_a_shots_on_goal, team_a_missed_shots, team_b_fouls, team_b_yellow_cards, team_b_red_cards);
            
        case 6: sub_event = rand() % 3;
            foul_event = rand () % 3;
            penalty_event_team_b(sub_event, foul_event, team_b_goals, team_b_shots_on_goal, team_b_missed_shots, team_a_fouls, team_a_yellow_cards, team_a_red_cards);
    }
}

void shot_event (int event_1, int sub_event, int& team_a_goals, int& team_b_goals, int& team_a_shots_on_goal, int& team_b_shots_on_goal, int& team_a_missed_shots, int& team_b_missed_shots, int& team_a_blocked_shots, int& team_b_blocked_shots)
{
    if (event_1 == 1)
    {
        switch (sub_event)
        {
            case 0: cout << "\nTeam A has scored! Fantastic Shot! \n";
                team_a_goals += 1;
                team_a_shots_on_goal += 1;
                break;
                
            case 1: cout << "\nTeam A shot on goal! But it's saved! \n";
                team_a_shots_on_goal += 1;
                break;
                
            case 2: cout << "\nTeam A's shot has missed the goal! \n";
                team_a_missed_shots += 1;
                break;
                
            case 3: cout << "\nTeam A's shot was blocked by Team B! \n";
                team_b_blocked_shots += 1;
                break;
        }
    }
    
    if (event_1 == 1)
    {
        switch (sub_event)
        {
            case 0: cout << "\nTeam B has scored! Fantastic Shot! \n";
                team_b_goals += 1;
                team_b_shots_on_goal += 1;
                break;
                
            case 1: cout << "\nTeam B shot on goal! But it's saved! \n";
                team_b_shots_on_goal += 1;
                break;
                
            case 2: cout << "\nTeam B's shot has missed the goal! \n";
                team_b_missed_shots += 1;
                break;
                
            case 3: cout << "\nTeam B's shot was blocked by Team A! \n";
                team_a_blocked_shots += 1;
                break;
                
        }
    }
    
}
// outputs commentary for different instances of the free kick event adds to the stat variables depending on which instance has occurred
void free_kick_event_team_a (int sub_event, int foul_event, int& team_a_goals, int& team_a_shots_on_goal, int& team_a_missed_shots, int& team_b_blocked_shots, int& team_b_fouls, int& team_b_yellow_cards, int& team_b_red_cards)
{
    team_b_fouls += 1;
    switch (foul_event)
    {
        case 0: cout << "\nTeam A has earned a Free Kick! No Card Given! ";
            break;
            
        case 1: cout <<  "\nTeam A has earned a Free Kick! Yellow Card Given! ";
            team_b_yellow_cards += 1;
            break;
            
        case 2: cout << "\nTeam A has earned a Free Kick! Red Card Given! ";
            team_b_red_cards +=1;
            break;
    }
    
    switch (sub_event)
    {
        case 0: cout << "\nTeam A has scored! Fantastic Free Kick! \n";
            team_a_goals += 1;
            team_a_shots_on_goal += 1;
            break;
            
        case 1: cout << "\nTeam A's free kick has been saved! \n";
            team_a_shots_on_goal +=1;
            break;
            
        case 2: cout << "\nTeam A's free kick has missed the net! \n";
            team_a_missed_shots += 1;
            break;
            
        case 3: cout << "\nTeam A's free kick has been blocked! \n";
            team_b_blocked_shots += 1;
            break;
    }
}

void free_kick_event_team_b (int sub_event, int foul_event, int& team_b_goals, int& team_b_shots_on_goal, int& team_b_missed_shots, int& team_a_blocked_shots, int& team_a_fouls, int& team_a_yellow_cards, int& team_a_red_cards)
{
    team_a_fouls += 1;
    switch (foul_event)
    {
        case 0: cout << "\nTeam B has earned a Free Kick! No Card Given! ";
            break;
            
        case 1: cout <<  "\nTeam B has earned a Free Kick! Yellow Card Given! ";
            team_a_yellow_cards += 1;
            break;
            
        case 2: cout << "\nTeam B has earned a Free Kick! Red Card Given! ";
            team_a_red_cards += 1;
            break;
    }
    
    switch (sub_event)
    {
        case 0: cout << "\nTeam B has scored! Fantastic Free Kick! \n";
            team_b_goals += 1;
            team_b_shots_on_goal += 1;
            break;
            
        case 1: cout << "\nTeam B's free kick has been saved! \n";
            team_b_shots_on_goal += 1;
            break;
            
        case 2: cout << "\nTeam B's free kick has missed the net! \n";
            team_b_missed_shots += 1;
            break;
            
        case 3: cout << "\nTeam B's free kick has been blocked! \n";
            team_a_blocked_shots += 1;
            break;
            
    }
}
// outputs commentary for different instances of the penalty event adds to the stat variables depending on which instance has occurred
void penalty_event_team_a (int sub_event, int foul_event, int& team_a_goals, int& team_a_shots_on_goal, int& team_a_missed_shots, int& team_b_fouls, int& team_b_yellow_cards, int& team_b_red_cards)
{
    team_b_fouls += 1;
    switch (foul_event)
    {
        case 0: cout << "\nTeam A has earned a Penalty! No Card Given! ";
            break;
            
        case 1: cout <<  "\nTeam A has earned a Penalty! Yellow Card Given! ";
            team_b_yellow_cards += 1;
            break;
            
        case 2: cout << "\nTeam A has earned a Penalty! Red Card Given! ";
            team_b_red_cards += 1;
            break;
    }
    
    switch (sub_event)
    {
        case 0: cout << "\nTeam A has scored! Fantastic Penalty! \n";
            team_a_goals += 1;
            team_a_shots_on_goal += 1;
            break;
            
        case 1: cout << "\nTeam A's Penalty has been saved! \n";
            team_a_shots_on_goal += 1;
            break;
            
        case 2: cout << "\nTeam A's Penalty has missed the net! \n";
            team_a_missed_shots += 1;
            break;
    }
}

void penalty_event_team_b (int sub_event, int foul_event, int& team_b_goals, int& team_b_shots_on_goal, int& team_b_missed_shots, int& team_a_fouls, int& team_a_yellow_cards, int& team_a_red_cards)
{
    team_a_fouls += 1;
    switch (foul_event)
    {
        case 0: cout << "\nTeam B has earned a Penalty! No Card Given! ";
            break;
            
        case 1: cout <<  "\nTeam B has earned a Penalty! Yellow Card Given! ";
            team_a_yellow_cards += 1;
            break;
            
        case 2: cout << "\nTeam B has earned a Penalty! Red Card Given! ";
            team_a_red_cards += 1;
            break;
    }
    
    switch (sub_event)
    {
        case 0: cout << "\nTeam B has scored! Fantastic Penalty! \n";
            team_b_goals += 1;
            break;
            
        case 1: cout << "\nTeam B's Penalty has been saved! \n";
            team_b_shots_on_goal += 1;
            break;
            
        case 2: cout << "\nTeam B's Penalty has missed the net! \n";
            team_b_missed_shots += 1;
            break;
    }
}

// outputs half-time stats
void stats_output_half (int team_a_goals, int team_b_goals, int team_a_shots_on_goal, int team_b_shots_on_goal, int team_a_missed_shots, int team_b_missed_shots, int team_a_blocked_shots, int team_b_blocked_shots, int team_a_fouls, int team_b_fouls, int team_a_yellow_cards, int team_b_yellow_cards, int team_a_red_cards, int team_b_red_cards)
{
    cout << "\n         Halftime Stats \n";
    cout << "Team A         Vs.         Team B \n";
    cout << team_a_goals << "             Goals          " << team_b_goals << endl;
    cout << team_a_shots_on_goal << "          Shots on Goal     " << team_b_shots_on_goal << endl;
    cout << team_a_missed_shots << "          Missed Shots      " << team_b_missed_shots << endl;
    cout << team_a_blocked_shots << "          Blocked Shots     " << team_a_blocked_shots << endl;
    cout << team_a_yellow_cards << "          Yellow Cards      " << team_b_yellow_cards << endl;
    cout << team_a_red_cards << "          Red Cards         " << team_b_red_cards << endl;
}
// outputs full-time stats
void stats_output_full (int team_a_goals, int team_b_goals, int team_a_shots_on_goal, int team_b_shots_on_goal, int team_a_missed_shots, int team_b_missed_shots, int team_a_blocked_shots, int team_b_blocked_shots, int team_a_fouls, int team_b_fouls, int team_a_yellow_cards, int team_b_yellow_cards, int team_a_red_cards, int team_b_red_cards)
{
    cout << "\n         Fulltime Stats \n";
    cout << "Team A         Vs.         Team B \n";
    cout << team_a_goals << "             Goals          " << team_b_goals << endl;
    cout << team_a_shots_on_goal << "          Shots on Goal     " << team_b_shots_on_goal << endl;
    cout << team_a_missed_shots << "          Missed Shots      " << team_b_missed_shots << endl;
    cout << team_a_blocked_shots << "          Blocked Shots     " << team_a_blocked_shots << endl;
    cout << team_a_yellow_cards << "          Yellow Cards      " << team_b_yellow_cards << endl;
    cout << team_a_red_cards << "          Red Cards         " << team_b_red_cards << endl;
}
