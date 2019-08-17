let Info: (state: state, player: player) => playerInfo = {
    let team =
      switch (player) {
      | Player1Hometeam
      | Player2Hometeam => "Hometeam"
      | Player1Awayteam
      | Player2Awayteam => "Awayteam"
      };

    let name =
      switch (player) {
      | Player1Hometeam => state.player1Hometeam.name
      | Player2Hometeam => state.player2Hometeam.name
      | Player1Awayteam => state.player1Awayteam.name
      | Player2Awayteam => state.player2Awayteam.name
      };

    let playerString =
      switch (player) {
      | Player1Hometeam
      | Player1Awayteam => "player1"
      | Player2Hometeam
      | Player2Awayteam => "player2"
      };

    let playerStringCap = String.capitalize(playerString);
    let fullId = playerString ++ team;
    {team, name, playerString, playerStringCap, fullId}
  };
};
