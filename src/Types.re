type screen =
  | GameScreen
  | HometeamScreen
  | AwayScreen;

type players =
  | Player1Hometeam
  | Player2Hometeam
  | Player1Awayteam
  | Player2Awayteam;

type jersey = {
  number: int,
  color: string,
};

type player = {
  name: string,
  picture: string,
  jersey,
};

type order =
  | One
  | Two
  | Three
  | Four;

type page = 
  | GamePage
  | EditHP1Page
  | EditHP2Page
  | EditAP1Page
  | EditAP2Page

/* Action declaration */
type action =
  | AddPointsHometeam
  | AddPointsAwayteam
  | ChangeName(string, players)
  | ChangeJersey(jersey, players)
  | UNDO
  | AddNote(string)
  | ShowView(screen)
  | ServiceOrder(players);

/* State declaration */
type state = {
  scoreH: int,
  scoreA: int,
  player1Hometeam: player,
  player2Hometeam: player,
  player1Awayteam: player,
  player2Awayteam: player,
  notes: list(string),
  actions: list(action),
  screen,
  serviceOrderSet1: list(players),
  serviceOrderSet2: list(players),
  serviceOrderSet3: list(players),
};

type playerInfo = {
  team: string,
  playerString: string,
  playerStringCap: string, 
  fullId: string,
  player: player,
};

let initialState: state = {
  scoreA: 0,
  scoreH: 0,
  player1Hometeam: {
    name: "player1",
    picture: "",
    jersey: {
      number: 1,
      color: "blue",
    },
  },
  player2Hometeam: {
    name: "player2",
    picture: "",
    jersey: {
      number: 2,
      color: "blue",
    },
  },
  player1Awayteam: {
    name: "player1",
    picture: "",
    jersey: {
      number: 1,
      color: "red",
    },
  },
  player2Awayteam: {
    name: "player2",
    picture: "",
    jersey: {
      number: 2,
      color: "blue",
    },
  },

  notes: [],
  actions: [],
  screen: GameScreen,
  serviceOrderSet1: [],
  serviceOrderSet2: [],
  serviceOrderSet3: [],
};

let reducer = (state, action) => {
  switch (action) {
  | AddPointsHometeam => {...state, scoreH: state.scoreH + 1}
  | AddPointsAwayteam => {...state, scoreA: state.scoreA + 1}
  | ChangeName(name, player) =>
    switch (player) {
    | Player1Hometeam => {
        ...state,
        player1Hometeam: {
          ...state.player1Hometeam,
          name: name,
        },
      }
          | Player2Hometeam => {
        ...state,
        player2Hometeam: {
          ...state.player2Hometeam,
          name: name,
        },
      }
          | Player1Awayteam => {
        ...state,
        player1Awayteam: {
          ...state.player1Awayteam,
          name: name,
        },
      }
          | Player2Awayteam => {
        ...state,
        player2Awayteam: {
          ...state.player2Awayteam,
          name: name,
        },
      }
    }
  | ChangeJersey(jersey, player) => 
    switch (player) {
     | Player1Hometeam => {
      ...state,
      player1Hometeam: {
          ...state.player1Hometeam,
          jersey: jersey,
        },
     }
      | Player2Hometeam => {
      ...state,
      player2Hometeam: {
          ...state.player2Hometeam,
          jersey: jersey,
        },
             }
      | Player1Awayteam => {
      ...state,
      player1Awayteam: {
          ...state.player1Awayteam,
          jersey: jersey,
        },
             }
      | Player2Awayteam => {
      ...state,
      player2Awayteam: {
          ...state.player2Awayteam,
          jersey: jersey,
        },
             }
    }  
  | UNDO => {...state, actions: [UNDO, ...state.actions]}
  | AddNote(value) => {...state, notes: [value, ...state.notes]}
  | ServiceOrder(player) =>
    switch (player) {
    | Player1Hometeam => {
        ...state,
        serviceOrderSet1: [Player2Hometeam, ...state.serviceOrderSet1],
      }
    | Player2Hometeam => {
        ...state,
        serviceOrderSet1: [Player2Hometeam, ...state.serviceOrderSet1],
      }
    | Player1Awayteam => {
        ...state,
        serviceOrderSet1: [Player1Awayteam, ...state.serviceOrderSet1],
      }
    | Player2Awayteam => {
        ...state,
        serviceOrderSet1: [Player2Awayteam, ...state.serviceOrderSet1],
      }
    }
  | ShowView(screen) => {...state, screen}
  };
};
