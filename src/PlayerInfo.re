
open Types; 

let info = (~playerType: players, ~state: state): playerInfo => {
  let team = 
    switch (playerType) {
    | Player1Hometeam
    | Player2Hometeam => "Hometeam"
    | Player1Awayteam
    | Player2Awayteam => "Awayteam"
    };

  let player =
    switch (playerType) {
    | Player1Hometeam => state.player1Hometeam
    | Player2Hometeam => state.player2Hometeam
    | Player1Awayteam => state.player1Awayteam
    | Player2Awayteam => state.player2Awayteam
    };

  let playerString =
    switch (playerType) {
    | Player1Hometeam
    | Player1Awayteam => "player1"
    | Player2Hometeam
    | Player2Awayteam => "player2"
    };

  let playerStringCap = String.capitalize(playerString);
  let fullId = playerString ++ team;
  {team, player, playerString, playerStringCap, fullId}
};

