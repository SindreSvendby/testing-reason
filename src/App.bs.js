// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Core = require("@material-ui/core");
var MaterialUi_Typography = require("@jsiebern/bs-material-ui/src/MaterialUi_Typography.bs.js");
var Caml_builtin_exceptions = require("bs-platform/lib/js/caml_builtin_exceptions.js");

function str(prim) {
  return prim;
}

function str_int(number) {
  return String(number);
}

var initialState = /* record */[
  /* scoreH */0,
  /* scoreA */0,
  /* namePlayer1Hometeam */"",
  /* namePlayer2Hometeam */"",
  /* namePlayer1Awayteam */"",
  /* namePlayer2Awayteam */"",
  /* jerseyColorPlayer1Hometeam */"",
  /* jerseyColorPlayer2Hometeam */"",
  /* jerseyColorPlayer1Awayteam */"",
  /* jerseyColorPlayer2Awayteam */""
];

function reducer(state, action) {
  console.log(state);
  if (typeof action === "number") {
    switch (action) {
      case 0 : 
          return /* record */[
                  /* scoreH */state[/* scoreH */0] + 1 | 0,
                  /* scoreA */state[/* scoreA */1],
                  /* namePlayer1Hometeam */state[/* namePlayer1Hometeam */2],
                  /* namePlayer2Hometeam */state[/* namePlayer2Hometeam */3],
                  /* namePlayer1Awayteam */state[/* namePlayer1Awayteam */4],
                  /* namePlayer2Awayteam */state[/* namePlayer2Awayteam */5],
                  /* jerseyColorPlayer1Hometeam */state[/* jerseyColorPlayer1Hometeam */6],
                  /* jerseyColorPlayer2Hometeam */state[/* jerseyColorPlayer2Hometeam */7],
                  /* jerseyColorPlayer1Awayteam */state[/* jerseyColorPlayer1Awayteam */8],
                  /* jerseyColorPlayer2Awayteam */state[/* jerseyColorPlayer2Awayteam */9]
                ];
      case 1 : 
          return /* record */[
                  /* scoreH */state[/* scoreH */0],
                  /* scoreA */state[/* scoreA */1] + 1 | 0,
                  /* namePlayer1Hometeam */state[/* namePlayer1Hometeam */2],
                  /* namePlayer2Hometeam */state[/* namePlayer2Hometeam */3],
                  /* namePlayer1Awayteam */state[/* namePlayer1Awayteam */4],
                  /* namePlayer2Awayteam */state[/* namePlayer2Awayteam */5],
                  /* jerseyColorPlayer1Hometeam */state[/* jerseyColorPlayer1Hometeam */6],
                  /* jerseyColorPlayer2Hometeam */state[/* jerseyColorPlayer2Hometeam */7],
                  /* jerseyColorPlayer1Awayteam */state[/* jerseyColorPlayer1Awayteam */8],
                  /* jerseyColorPlayer2Awayteam */state[/* jerseyColorPlayer2Awayteam */9]
                ];
      case 2 : 
      case 3 : 
          throw [
                Caml_builtin_exceptions.match_failure,
                /* tuple */[
                  "App.re",
                  47,
                  2
                ]
              ];
      
    }
  } else {
    switch (action.tag | 0) {
      case 0 : 
          return /* record */[
                  /* scoreH */state[/* scoreH */0],
                  /* scoreA */state[/* scoreA */1],
                  /* namePlayer1Hometeam */action[0],
                  /* namePlayer2Hometeam */state[/* namePlayer2Hometeam */3],
                  /* namePlayer1Awayteam */state[/* namePlayer1Awayteam */4],
                  /* namePlayer2Awayteam */state[/* namePlayer2Awayteam */5],
                  /* jerseyColorPlayer1Hometeam */state[/* jerseyColorPlayer1Hometeam */6],
                  /* jerseyColorPlayer2Hometeam */state[/* jerseyColorPlayer2Hometeam */7],
                  /* jerseyColorPlayer1Awayteam */state[/* jerseyColorPlayer1Awayteam */8],
                  /* jerseyColorPlayer2Awayteam */state[/* jerseyColorPlayer2Awayteam */9]
                ];
      case 1 : 
          return /* record */[
                  /* scoreH */state[/* scoreH */0],
                  /* scoreA */state[/* scoreA */1],
                  /* namePlayer1Hometeam */state[/* namePlayer1Hometeam */2],
                  /* namePlayer2Hometeam */action[0],
                  /* namePlayer1Awayteam */state[/* namePlayer1Awayteam */4],
                  /* namePlayer2Awayteam */state[/* namePlayer2Awayteam */5],
                  /* jerseyColorPlayer1Hometeam */state[/* jerseyColorPlayer1Hometeam */6],
                  /* jerseyColorPlayer2Hometeam */state[/* jerseyColorPlayer2Hometeam */7],
                  /* jerseyColorPlayer1Awayteam */state[/* jerseyColorPlayer1Awayteam */8],
                  /* jerseyColorPlayer2Awayteam */state[/* jerseyColorPlayer2Awayteam */9]
                ];
      case 2 : 
          return /* record */[
                  /* scoreH */state[/* scoreH */0],
                  /* scoreA */state[/* scoreA */1],
                  /* namePlayer1Hometeam */state[/* namePlayer1Hometeam */2],
                  /* namePlayer2Hometeam */state[/* namePlayer2Hometeam */3],
                  /* namePlayer1Awayteam */action[0],
                  /* namePlayer2Awayteam */state[/* namePlayer2Awayteam */5],
                  /* jerseyColorPlayer1Hometeam */state[/* jerseyColorPlayer1Hometeam */6],
                  /* jerseyColorPlayer2Hometeam */state[/* jerseyColorPlayer2Hometeam */7],
                  /* jerseyColorPlayer1Awayteam */state[/* jerseyColorPlayer1Awayteam */8],
                  /* jerseyColorPlayer2Awayteam */state[/* jerseyColorPlayer2Awayteam */9]
                ];
      case 3 : 
          return /* record */[
                  /* scoreH */state[/* scoreH */0],
                  /* scoreA */state[/* scoreA */1],
                  /* namePlayer1Hometeam */state[/* namePlayer1Hometeam */2],
                  /* namePlayer2Hometeam */state[/* namePlayer2Hometeam */3],
                  /* namePlayer1Awayteam */state[/* namePlayer1Awayteam */4],
                  /* namePlayer2Awayteam */action[0],
                  /* jerseyColorPlayer1Hometeam */state[/* jerseyColorPlayer1Hometeam */6],
                  /* jerseyColorPlayer2Hometeam */state[/* jerseyColorPlayer2Hometeam */7],
                  /* jerseyColorPlayer1Awayteam */state[/* jerseyColorPlayer1Awayteam */8],
                  /* jerseyColorPlayer2Awayteam */state[/* jerseyColorPlayer2Awayteam */9]
                ];
      case 4 : 
          return /* record */[
                  /* scoreH */state[/* scoreH */0],
                  /* scoreA */state[/* scoreA */1],
                  /* namePlayer1Hometeam */state[/* namePlayer1Hometeam */2],
                  /* namePlayer2Hometeam */state[/* namePlayer2Hometeam */3],
                  /* namePlayer1Awayteam */state[/* namePlayer1Awayteam */4],
                  /* namePlayer2Awayteam */state[/* namePlayer2Awayteam */5],
                  /* jerseyColorPlayer1Hometeam */action[0],
                  /* jerseyColorPlayer2Hometeam */state[/* jerseyColorPlayer2Hometeam */7],
                  /* jerseyColorPlayer1Awayteam */state[/* jerseyColorPlayer1Awayteam */8],
                  /* jerseyColorPlayer2Awayteam */state[/* jerseyColorPlayer2Awayteam */9]
                ];
      case 5 : 
          return /* record */[
                  /* scoreH */state[/* scoreH */0],
                  /* scoreA */state[/* scoreA */1],
                  /* namePlayer1Hometeam */state[/* namePlayer1Hometeam */2],
                  /* namePlayer2Hometeam */state[/* namePlayer2Hometeam */3],
                  /* namePlayer1Awayteam */state[/* namePlayer1Awayteam */4],
                  /* namePlayer2Awayteam */state[/* namePlayer2Awayteam */5],
                  /* jerseyColorPlayer1Hometeam */state[/* jerseyColorPlayer1Hometeam */6],
                  /* jerseyColorPlayer2Hometeam */action[0],
                  /* jerseyColorPlayer1Awayteam */state[/* jerseyColorPlayer1Awayteam */8],
                  /* jerseyColorPlayer2Awayteam */state[/* jerseyColorPlayer2Awayteam */9]
                ];
      case 6 : 
          return /* record */[
                  /* scoreH */state[/* scoreH */0],
                  /* scoreA */state[/* scoreA */1],
                  /* namePlayer1Hometeam */state[/* namePlayer1Hometeam */2],
                  /* namePlayer2Hometeam */state[/* namePlayer2Hometeam */3],
                  /* namePlayer1Awayteam */state[/* namePlayer1Awayteam */4],
                  /* namePlayer2Awayteam */state[/* namePlayer2Awayteam */5],
                  /* jerseyColorPlayer1Hometeam */state[/* jerseyColorPlayer1Hometeam */6],
                  /* jerseyColorPlayer2Hometeam */state[/* jerseyColorPlayer2Hometeam */7],
                  /* jerseyColorPlayer1Awayteam */action[0],
                  /* jerseyColorPlayer2Awayteam */state[/* jerseyColorPlayer2Awayteam */9]
                ];
      case 7 : 
          return /* record */[
                  /* scoreH */state[/* scoreH */0],
                  /* scoreA */state[/* scoreA */1],
                  /* namePlayer1Hometeam */state[/* namePlayer1Hometeam */2],
                  /* namePlayer2Hometeam */state[/* namePlayer2Hometeam */3],
                  /* namePlayer1Awayteam */state[/* namePlayer1Awayteam */4],
                  /* namePlayer2Awayteam */state[/* namePlayer2Awayteam */5],
                  /* jerseyColorPlayer1Hometeam */state[/* jerseyColorPlayer1Hometeam */6],
                  /* jerseyColorPlayer2Hometeam */state[/* jerseyColorPlayer2Hometeam */7],
                  /* jerseyColorPlayer1Awayteam */state[/* jerseyColorPlayer1Awayteam */8],
                  /* jerseyColorPlayer2Awayteam */action[0]
                ];
      
    }
  }
}

function App(Props) {
  var match = React.useReducer(reducer, initialState);
  var dispatch = match[1];
  var state = match[0];
  return React.createElement("div", undefined, React.createElement("div", undefined, String(state[/* scoreH */0])), React.createElement("button", {
                  onClick: (function (_event) {
                      return Curry._1(dispatch, /* AddPointsHometeam */0);
                    })
                }, "Add Point Hometeam"), React.createElement("div", undefined, String(state[/* scoreA */1])), React.createElement("button", {
                  onClick: (function (_event) {
                      return Curry._1(dispatch, /* AddPointsAwayteam */1);
                    })
                }, "Add Point Awayteam"), React.createElement("form", undefined, React.createElement("label", {
                      htmlFor: "player1Hometeam"
                    }, "Player1 HomeTeam"), React.createElement("input", {
                      name: "player1Hometeam",
                      onChange: (function ($$event) {
                          return Curry._1(dispatch, /* ChangeNamePlayer1Hometeam */Block.__(0, [$$event.target.value]));
                        })
                    })), React.createElement("form", undefined, React.createElement("label", {
                      htmlFor: "player2Hometeam"
                    }, "Player2 HomeTeam"), React.createElement("input", {
                      name: "player2Hometeam",
                      onChange: (function ($$event) {
                          return Curry._1(dispatch, /* ChangeNamePlayer2Awayteam */Block.__(3, [$$event.target.value]));
                        })
                    })), React.createElement("form", undefined, React.createElement("label", {
                      htmlFor: "player1Awayteam"
                    }, "Player1 Awayteam"), React.createElement("input", {
                      name: "player1Awayteam",
                      onChange: (function ($$event) {
                          return Curry._1(dispatch, /* ChangeNamePlayer1Awayteam */Block.__(2, [$$event.target.value]));
                        })
                    })), React.createElement(Core.Typography, MaterialUi_Typography.makeProps(undefined, "Icon Types:", undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, /* H6 */16110, undefined, undefined, undefined, undefined, undefined, /* () */0)), React.createElement("form", undefined, React.createElement("label", {
                      htmlFor: "player2Awayteam"
                    }, "Player2 Awayteam"), React.createElement("input", {
                      name: "player2Awayteam",
                      onChange: (function ($$event) {
                          return Curry._1(dispatch, /* ChangeNamePlayer2Awayteam */Block.__(3, [$$event.target.value]));
                        })
                    })));
}

var make = App;

exports.str = str;
exports.str_int = str_int;
exports.initialState = initialState;
exports.reducer = reducer;
exports.make = make;
/* react Not a pure module */
