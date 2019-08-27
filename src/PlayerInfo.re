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

  Js.log2("info", player);

  let playerString =
    switch (playerType) {
    | Player1Hometeam
    | Player1Awayteam => "player1"
    | Player2Hometeam
    | Player2Awayteam => "player2"
    };

  let playerStringCap = String.capitalize(playerString);
  let fullId = playerString ++ team;
  {team, player, playerString, playerStringCap, fullId};
};

let pageToPlayer = (page: page) =>
  switch (page) {
  | EditHP1Page => Player1Hometeam
  | EditHP2Page => Player2Hometeam
  | EditAP1Page => Player1Awayteam
  | EditAP2Page => Player2Awayteam
  | _x =>
    Js.log("Error: pageToPlayer failed, falback to Player1Hometeam");
    Js.log(_x);
    Player1Hometeam;
  };

let indexToPage = (index: int): page =>
  switch (index) {
  | 0 => GamePage
  | 1 => EditHP1Page
  | 2 => EditHP2Page
  | 3 => EditAP1Page
  | 4 => EditAP2Page
  | _ => GamePage
  };

let indexToPlayer = (index: int) => index->indexToPage->pageToPlayer;