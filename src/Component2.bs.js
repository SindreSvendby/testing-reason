// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");

function str(prim) {
  return prim;
}

function str_int(number) {
  return String(number);
}

function update(action) {
  return /* Update */Block.__(0, [action]);
}

var component = ReasonReact.reducerComponent("Scoreboard");

function make(_children) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (param) {
              var send = param[/* send */3];
              var state = param[/* state */1];
              return React.createElement("div", undefined, React.createElement("div", undefined, String(state[/* scoreH */0])), React.createElement("button", {
                              onClick: (function (_event) {
                                  return Curry._1(send, /* AddPointsHometeam */0);
                                })
                            }, "Add Point"), React.createElement("div", undefined, String(state[/* scoreA */1])), React.createElement("button", {
                              onClick: (function (_event) {
                                  return Curry._1(send, /* AddPointsAwayteam */1);
                                })
                            }, "Add Point"));
            }),
          /* initialState */(function (param) {
              return /* record */[
                      /* scoreH */0,
                      /* scoreA */0
                    ];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.str = str;
exports.str_int = str_int;
exports.update = update;
exports.component = component;
exports.make = make;
/* component Not a pure module */