<?php

function findIndex($searchTerm)
{
    $options = array("paper", "rock", "scissors");
    $index = array_search($searchTerm, $options);
    return $index;
}

function winner($player, $computer)
{
    $comp_index = findIndex($computer);
    $user_index = findIndex($player);
    $comp_index_winner = ($comp_index + 1)%3;
    $user_index_winner = ($user_index + 1)%3;
    // print "\n";
    // print "my index :" . $user_index  . "\n";
    // print "comp index :" . $comp_index . "\n";

    if($comp_index == $user_index_winner)
    {
        print "Congratulations! You won! The computer chose " . $computer . ".\n";

    }
    else if ($comp_index_winner == $user_index)
    {
        print "Sorry, you lost. The computer chose " . $computer . ".\n";

    }
    else
    {//wont ever happen cus tie is handled
        print "Tierrr!";
    }
}

function tie($player, $computer)
{
    if($player == $computer)
        return true;
    else
        return false;
}

function get_choice()
{
    $options = array("paper", "rock", "scissors");
    $index = array_rand($options);
    return $options[$index];
}

function check($choice)
{
    if($choice != "paper" && $choice != "rock" && $choice !=  "scissors")
        return true;
    return false;
}
print "Choose rock, paper, or scissors: ";
$choice = fgets(STDIN);
$choice = trim($choice);
if(check($choice))
{
    print "invalid choice\n";
    return;
}

$comp_choice = get_choice();

if(tie($choice,$comp_choice))
    print "Tie!";
else
    winner($choice,$comp_choice)
?>