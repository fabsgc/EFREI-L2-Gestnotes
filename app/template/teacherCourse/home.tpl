<include src="include/header"/>

<h4>Professeur principal</h4>
<table class="table">
	<thead>
		<tr>
			<th class="matricule">Id</th>
			<th>Nom</th>
		<tr>
	</thead>
	<tbody>
		<if condition="count($coursesPrincipal) > 0">
			<foreach loop="$coursesPrincipal as $data">
				<tr>
					<td>{$data['id']}</td>
					<td>{$data['name']}</td>
				</tr>
			</foreach>
		<else/>
			<tr>
				<td class="empty" colspan="2">Aucun cours</td>
			</tr>
		</if>
	<tbody>
</table>

<h4>Professeur assistant</h4>
<table class="table">
	<thead>
		<tr>
			<th class="matricule">Id</th>
			<th>Nom</th>
		<tr>
	</thead>
	<tbody>
		<if condition="count($coursesAssistant) > 0">
			<foreach loop="$coursesAssistant as $data">
				<tr>
					<td>{$data['id']}</td>
					<td>{$data['name']}</td>
				</tr>
			</foreach>
		<else/>
			<tr>
				<td class="empty" colspan="2">Aucun cours</td>
			</tr>
		</if>
	<tbody>
</table>

<include src="include/footer"/>