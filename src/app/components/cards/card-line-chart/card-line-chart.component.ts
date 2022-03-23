import { Component, OnInit, AfterViewInit } from "@angular/core";
import Chart from "chart.js";

//Imports para Firebase
import { Tutorial } from "src/app/models/tutorial.model";
import { TutorialService } from "src/app/services/tutorial.service";
import { map } from 'rxjs/operators'

@Component({
  selector: "app-card-line-chart",
  templateUrl: "./card-line-chart.component.html",
})
export class CardLineChartComponent implements OnInit {

  //Datos firebase
  data?: any = Tutorial;

  constructor(public tutorialService: TutorialService) {}

  ngOnInit(): void {
    this.retrieveTutorials();
  }
  retrieveTutorials(): void {
    this.tutorialService.getAll().snapshotChanges().pipe(
      map(changes =>
        changes.map(c =>
          ({ key: c.payload.key, ...c.payload.val() })
        )
      )
    ).subscribe(data => {
      this.data = data;
      console.log(this.data);
    });
  }


  ngAfterViewInit() {
    var config = {
      type: "line",
      data: {
        labels: [
          "12:00",
          "13:00",
          "14:00",
          "15:00",
          "16:00",
          "17:00",
        ],
        datasets: [
          {
            label: "Temperatura porcentual",
            backgroundColor: "#4c51bf",
            borderColor: "#4c51bf",
            data: [27, 25, 30, 28, 28, 27, 24.5],
            fill: false,
          },
          {
            label: "Humedad porcentual",
            fill: false,
            backgroundColor: "#fff",
            borderColor: "#fff",
            data: [29, 27, 40, 74, 96, 27, 37],
          },
        ],
      },
      options: {
        maintainAspectRatio: false,
        responsive: true,
        title: {
          display: false,
          text: "Sales Charts",
          fontColor: "white",
        },
        legend: {
          labels: {
            fontColor: "white",
          },
          align: "end",
          position: "bottom",
        },
        tooltips: {
          mode: "index",
          intersect: false,
        },
        hover: {
          mode: "nearest",
          intersect: true,
        },
        scales: {
          xAxes: [
            {
              ticks: {
                fontColor: "rgba(255,255,255,.7)",
              },
              display: true,
              scaleLabel: {
                display: false,
                labelString: "Month",
                fontColor: "white",
              },
              gridLines: {
                display: false,
                borderDash: [2],
                borderDashOffset: [2],
                color: "rgba(33, 37, 41, 0.3)",
                zeroLineColor: "rgba(0, 0, 0, 0)",
                zeroLineBorderDash: [2],
                zeroLineBorderDashOffset: [2],
              },
            },
          ],
          yAxes: [
            {
              ticks: {
                fontColor: "rgba(255,255,255,.7)",
              },
              display: true,
              scaleLabel: {
                display: false,
                labelString: "Value",
                fontColor: "white",
              },
              gridLines: {
                borderDash: [3],
                borderDashOffset: [3],
                drawBorder: false,
                color: "rgba(255, 255, 255, 0.15)",
                zeroLineColor: "rgba(33, 37, 41, 0)",
                zeroLineBorderDash: [2],
                zeroLineBorderDashOffset: [2],
              },
            },
          ],
        },
      },
    };
    let ctx: any = document.getElementById("line-chart") as HTMLCanvasElement;
    ctx = ctx.getContext("2d");
    new Chart(ctx, config);
  }
}
